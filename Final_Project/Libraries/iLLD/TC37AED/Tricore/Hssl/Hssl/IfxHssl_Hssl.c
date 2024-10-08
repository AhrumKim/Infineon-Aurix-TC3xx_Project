/**
 * \file IfxHssl_Hssl.c
 * \brief HSSL HSSL details
 *
 * \version iLLD_1_0_1_17_0
 * \copyright Copyright (c) 2019 Infineon Technologies AG. All rights reserved.
 *
 *
 *                                 IMPORTANT NOTICE
 *
 * Use of this file is subject to the terms of use agreed between (i) you or
 * the company in which ordinary course of business you are acting and (ii)
 * Infineon Technologies AG or its licensees. If and as long as no such terms
 * of use are agreed, use of this file is subject to following:
 *
 * Boost Software License - Version 1.0 - August 17th, 2003
 *
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 *
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer, must
 * be included in all copies of the Software, in whole or in part, and all
 * derivative works of the Software, unless such copies or derivative works are
 * solely in the form of machine-executable object code generated by a source
 * language processor.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 *
 *
 */

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "IfxHssl_Hssl.h"

/******************************************************************************/
/*-------------------------Function Implementations---------------------------*/
/******************************************************************************/

void IfxHssl_Hssl_checkErrors(IfxHssl_Hssl *hssl)
{
    Ifx_HSSL *hsslSFR = hssl->hssl; /* pointer to HSSL registers */

    /* store the errors in the structure */
    if (hsslSFR->MFLAGS.B.NACK != 0)
    {
        hssl->errorFlags.notAcknowledgeError = 1;
    }

    if (hsslSFR->MFLAGS.B.TTE != 0)
    {
        hssl->errorFlags.transactionTagError = 1;
    }

    if (hsslSFR->MFLAGS.B.TIMEOUT != 0)
    {
        hssl->errorFlags.timeoutError = 1;
    }

    if (hsslSFR->MFLAGS.B.UNEXPECTED != 0)
    {
        hssl->errorFlags.unexpectedError = 1;
    }

    if (hsslSFR->MFLAGS.B.MAV != 0)
    {
        hssl->errorFlags.memoryAccessViolation = 1;
    }

    if (hsslSFR->MFLAGS.B.SRIE != 0)
    {
        hssl->errorFlags.busAccessError = 1;
    }

    if (hsslSFR->MFLAGS.B.PIE1 != 0)
    {
        hssl->errorFlags.channelNumberCodeError = 1;
    }

    if (hsslSFR->MFLAGS.B.PIE2 != 0)
    {
        hssl->errorFlags.dataLengthError = 1;
    }

    if (hsslSFR->MFLAGS.B.CRCE != 0)
    {
        hssl->errorFlags.crcError = 1;
    }
}


void IfxHssl_Hssl_clearErrorFlags(IfxHssl_Hssl *hssl)
{
    hssl->errorFlags.notAcknowledgeError    = 0;
    hssl->errorFlags.transactionTagError    = 0;
    hssl->errorFlags.timeoutError           = 0;
    hssl->errorFlags.unexpectedError        = 0;
    hssl->errorFlags.memoryAccessViolation  = 0;
    hssl->errorFlags.busAccessError         = 0;
    hssl->errorFlags.channelNumberCodeError = 0;
    hssl->errorFlags.dataLengthError        = 0;
    hssl->errorFlags.crcError               = 0;
}


void IfxHssl_Hssl_delay(IfxHssl_Hsct *hsct)
{
    uint32 i;
    IFX_UNUSED_PARAMETER(hsct);

    for (i = 0; i < 8000; i++)
    {
        __nop();
    }
}


void IfxHssl_Hssl_initChannel(IfxHssl_Hssl_Channel *channel, const IfxHssl_Hssl_ChannelConfig *channelConfig)
{
    channel->hssl                = channelConfig->hssl;                /* adding HSSL register pointer to channel handle */
    channel->hsct                = channelConfig->hsct;                /* adding HSCT register pointer to channel handle */

    channel->channelId           = channelConfig->channelId;           /* adding channel id to channel handle */
    channel->currentFrameRequest = IfxHssl_Hssl_FrameRequest_noAction; /* default request, no action */

    channel->streamingModeOn     = FALSE;                              /* command mode (used in waitAcknowledge function) */
    channel->streamingMode       = channelConfig->streamingMode;       /* adding streaming mode to channel handle */
    channel->loopBack            = channelConfig->loopBack;            /* adding loopback selection to channel handle */
}


void IfxHssl_Hssl_initChannelConfig(IfxHssl_Hssl_ChannelConfig *channelConfig, IfxHssl_Hssl *hssl, IfxHssl_Hsct *hsct)
{
    channelConfig->hssl          = hssl->hssl;
    channelConfig->hsct          = hsct->hsct;

    channelConfig->channelId     = IfxHssl_ChannelId_0;          /* default channel 0 */
    channelConfig->streamingMode = IfxHssl_StreamingMode_single; /* default streaming mode continuous */
    channelConfig->loopBack      = hsct->loopBack;
    hssl->loopBack               = hsct->loopBack;               /* copy to hssl handle, used in trasfer apis */
}


void IfxHssl_Hssl_initHsctModule(IfxHssl_Hsct *hsct, const IfxHssl_Hsct_Config *config)
{
    Ifx_HSCT *hsctSFR = config->hsct;   /* pointer to HSCT registers */

    hsct->hsct     = hsctSFR;           /* adding HSCT register pointer to module handle */
    hsct->loopBack = config->loopBack;  /* adding loopback selection to module handle */

#ifndef IFXHSSL_HSCT_DISABLE_PINCONFIG
    /* Pad initialisiation */
    IfxPort_setPinModeInput(&MODULE_P21, 2, IfxPort_InputMode_noPullDevice);                          /* RXDN */
    IfxPort_setPinModeInput(&MODULE_P21, 3, IfxPort_InputMode_noPullDevice);                          /* RXDP */
    IfxPort_setPinModeOutput(&MODULE_P21, 4, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); /* TXDN */
    IfxPort_setPinModeOutput(&MODULE_P21, 5, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); /* TXDP */

    /* select the clock direction */
    if (config->interfaceMode == IfxHssl_InterfaceMode_master)
    {
        IfxPort_setPinModeOutput(&MODULE_P20, 0, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_alt5); /* CLKOUT */
#ifdef IFXHSSL_HSCT_ENABLE_SYS_CLK_DIV_2
        IfxPort_setPinPadDriver(&MODULE_P20, 0, IfxPort_PadDriver_cmosAutomotiveSpeed2);
#else
        IfxPort_setPinPadDriver(&MODULE_P20, 0, IfxPort_PadDriver_cmosAutomotiveSpeed1);
#endif
    }
    else
    {
        IfxPort_setPinModeInput(&MODULE_P20, 0, IfxPort_InputMode_pullDown); /* CLKIN */
    }

    if (config->loopBack == FALSE)
    /* LVDS configuration */
    {
        uint16 psw = IfxScuWdt_getCpuWatchdogPassword();
        IfxScuWdt_clearCpuEndinit(psw);         /* clears the endinit protection */

        P21_LPCR1.B.REN_CTRL = 1;
        P21_LPCR1.B.RX_EN    = 1;

        P21_LPCR2.B.TEN_CTRL = 1;
        P21_LPCR2.B.TX_EN    = 1;
        P21_LPCR2.B.TX_PD    = 0;
        P21_LPCR1.B.LVDSM    = 0;     /* Setting P21 to LVDS-H mode */

        IfxScuWdt_setCpuEndinit(psw); /* sets the endinit protection back on */
    }

#endif

    /* HSCT initialisation */
    IfxHssl_enableHsctModule(hsctSFR);                                          /* enabling the HSCT module */

    hsctSFR->IRQCLR.B.TXTECLR = 1;                                              /* due to AI */

    /* slave interface initialisation */
    if (config->interfaceMode == IfxHssl_InterfaceMode_slave)                   /* slave mode initialisation */
    {
        hsctSFR->INIT.B.IFM        = IfxHssl_InterfaceMode_slave;               /* slave mode */
        hsctSFR->INIT.B.SYS_CLK_EN = 0;                                         /* disabling the system clock */
#ifdef IFXHSSL_HSCT_ENABLE_REF_CLK_10MHZ
        hsctSFR->INIT.B.SRCF       = IfxHssl_RefClockFrequency_10Mhz;           /* Reference Clock Frequency rate 10 MHz */
#else
        hsctSFR->INIT.B.SRCF       = IfxHssl_RefClockFrequency_20Mhz;           /* Reference Clock Frequency rate 20 MHz */
#endif

#ifdef IFXHSSL_HSCT_ENABLE_SYS_CLK_DIV_2
        hsctSFR->INIT.B.SSCF     = IfxHssl_SysClockDivider_2;                   /* SysClk divider 1/2 */
#else
        hsctSFR->INIT.B.SSCF     = IfxHssl_SysClockDivider_1;                   /* SysClk divider 1/1 */
#endif
        hsctSFR->CONFIGPHY.B.PON = 1;                                           /* Peripheral power on */

        hsctSFR->DISABLE.U       = 0;
    }

    /* master interface initialisation */
    else                                                                        /* master mode initialisation */
    {
        hsctSFR->INIT.B.IFM        = IfxHssl_InterfaceMode_master;              /* master mode */
        hsctSFR->INIT.B.SYS_CLK_EN = 1;                                         /* enabling the system clock */
#ifdef IFXHSSL_HSCT_ENABLE_REF_CLK_10MHZ
        hsctSFR->INIT.B.SRCF       = IfxHssl_RefClockFrequency_10Mhz;           /* Reference Clock Frequency rate 10 MHz */
#else
        hsctSFR->INIT.B.SRCF       = IfxHssl_RefClockFrequency_20Mhz;           /* Reference Clock Frequency rate 20 MHz */
#endif

#ifdef IFXHSSL_HSCT_ENABLE_SYS_CLK_DIV_2
        hsctSFR->INIT.B.SSCF       = IfxHssl_SysClockDivider_2;                 /* SysClk divider 1/2 */
#else
        hsctSFR->INIT.B.SSCF       = IfxHssl_SysClockDivider_1;                 /* SysClk divider 1/1 */
#endif
        hsctSFR->CONFIGPHY.B.PON   = 1;                                         /* Peripheral power on */
        hsctSFR->IFCTRL.B.MTXSPEED = IfxHssl_MasterModeTxSpeed_lowSpeed;        /* Tx low speed */
        hsctSFR->IFCTRL.B.MRXSPEED = IfxHssl_MasterModeRxSpeed_lowSpeed;        /* Rx low speed */

        /* change from low speed to high speed */
        if (config->highSpeedMode)
        {
            hsctSFR->IFCTRL.B.MTXSPEED = IfxHssl_MasterModeTxSpeed_highSpeed;      /* Tx high speed */
            hsctSFR->IFCTRL.B.MRXSPEED = IfxHssl_MasterModeRxSpeed_highSpeed;      /* Rx high speed */
        }

        hsctSFR->DISABLE.U = 0;

        while (hsctSFR->STATPHY.B.PLOCK == 0)                                      /* wait until pll is locked */
        {}
    }
}


void IfxHssl_Hssl_initHsctModuleConfig(IfxHssl_Hsct_Config *config, Ifx_HSCT *hsct)
{
    config->hsct = hsct;

    /* interface mode */
    config->interfaceMode = IfxHssl_InterfaceMode_master;

    /* high speed mode disabled */
    config->highSpeedMode = FALSE;

    config->loopBack      = FALSE; /* default with out loopback */
}


void IfxHssl_Hssl_initHsslModule(IfxHssl_Hssl *hssl, const IfxHssl_Hssl_Config *config)
{
    Ifx_HSSL *hsslSFR = config->hssl;                                   /* pointer to HSSL registers */

    hssl->hssl = hsslSFR;                                               /* adding HSSL register pointer to module handle */

    /* HSSL initialisation */
    IfxHssl_enableHsslModule(hsslSFR);                                  /* enabling the HSSL module */
    hsslSFR->CFG.B.PREDIV = config->preDivider;                         /* predivivder */
    hsslSFR->CFG.B.SCM    = 0;                                          /* command mode */

    /* Access windows */
    hsslSFR->AW[0].AWSTART.U = config->accessWindow0.start;             /* start of access window */
    hsslSFR->AW[0].AWEND.U   = config->accessWindow0.end;               /* end of access window */
    hsslSFR->AW[1].AWSTART.U = config->accessWindow1.start;             /* start of access window */
    hsslSFR->AW[1].AWEND.U   = config->accessWindow1.end;               /* end of access window */
    hsslSFR->AW[2].AWSTART.U = config->accessWindow2.start;             /* start of access window */
    hsslSFR->AW[2].AWEND.U   = config->accessWindow2.end;               /* end of access window */
    hsslSFR->AW[3].AWSTART.U = config->accessWindow3.start;             /* start of access window */
    hsslSFR->AW[3].AWEND.U   = config->accessWindow3.end;               /* end of access window */

    hsslSFR->AR.U            = 0x000000ff;                              /* allow read/write access for all windows */

    hsslSFR->MFLAGSCL.B.INIC = 1;                                       /* chnage into run mode */
    hsslSFR->TIDADD.U        = (Ifx_UReg_32Bit)IFXHSSL_JTAG_ID_ADDRESS; /* Writing JTAG_ID of the device to TIDADD.This'll be used in the response when the other device queries for ID */

    while (hsslSFR->MFLAGS.B.INI)                                       /* wait until the mode changes */
    {}
}


void IfxHssl_Hssl_initHsslModuleConfig(IfxHssl_Hssl_Config *config, Ifx_HSSL *hssl)
{
    config->hssl = hssl;

    /* Access windows */
    config->accessWindow0.start = 0x00000000; /* start of access window */
    config->accessWindow0.end   = 0xffffffff; /* end of access window */
    config->accessWindow1.start = 0x00000000; /* start of access window */
    config->accessWindow1.end   = 0xffffffff; /* end of access window */
    config->accessWindow2.start = 0x00000000; /* start of access window */
    config->accessWindow2.end   = 0xffffffff; /* end of access window */
    config->accessWindow3.start = 0x00000000; /* start of access window */
    config->accessWindow3.end   = 0xffffffff; /* end of access window */

    /* predivider */
    config->preDivider = 256;
}


IfxHssl_Hssl_Status IfxHssl_Hssl_prepareStream(IfxHssl_Hssl_Channel *channel, uint32 slaveTargetAddress, Ifx_SizeT count)
{
    IfxHssl_ChannelId channelId = channel->channelId;
    Ifx_HSSL_TS_FC    tsfcReg;

    if (channelId == IfxHssl_ChannelId_2)
    {
        return IfxHssl_Hssl_Status_error;
    }

    /* target start address to memeroy block 0 on target device (writing into HSSL_TSSA0 of the target) */
    IfxHssl_Hssl_singleFrameRequest(channel, IfxHssl_Hssl_FrameRequest_writeFrame, (uint32)&channel->hssl->TS.SA[0], slaveTargetAddress, IfxHssl_DataLength_32bit);

    while (IfxHssl_Hssl_waitAcknowledge(channel) != IfxHssl_Hssl_Status_ok)
    {
        if (IfxHssl_Hssl_waitAcknowledge(channel) == IfxHssl_Hssl_Status_error)
        {
            return IfxHssl_Hssl_Status_error;
        }
    }

    /* Precautionary measure on target for any last streaming interruption */
    /* Read count register on the target */
    IfxHssl_Hssl_read(channel, (uint32)&channel->hssl->TS.FC, IfxHssl_DataLength_32bit);

    while (IfxHssl_Hssl_waitAcknowledge(channel) != IfxHssl_Hssl_Status_ok)
    {
        if (IfxHssl_Hssl_waitAcknowledge(channel) == IfxHssl_Hssl_Status_error)
        {
            return IfxHssl_Hssl_Status_error;
        }
    }

    tsfcReg.U          = IfxHssl_Hssl_getReadData(channel);
    tsfcReg.B.RELCOUNT = tsfcReg.B.CURCOUNT;
    /* Set the RELCOUNT equal to CURCOUNT on the target */
    IfxHssl_Hssl_singleFrameRequest(channel, IfxHssl_Hssl_FrameRequest_writeFrame, (uint32)&channel->hssl->TS.FC, count, IfxHssl_DataLength_16bit);

    while (IfxHssl_Hssl_waitAcknowledge(channel) != IfxHssl_Hssl_Status_ok)
    {
        if (IfxHssl_Hssl_waitAcknowledge(channel) == IfxHssl_Hssl_Status_error)
        {
            return IfxHssl_Hssl_Status_error;
        }
    }

    /* Disable the streaming on the target */
    IfxHssl_Hssl_singleFrameRequest(channel, IfxHssl_Hssl_FrameRequest_writeFrame, (uint32)&channel->hssl->MFLAGSCL, (1 << IFX_HSSL_MFLAGSCL_TSEC_OFF), IfxHssl_DataLength_32bit);

    while (IfxHssl_Hssl_waitAcknowledge(channel) != IfxHssl_Hssl_Status_ok)
    {
        if (IfxHssl_Hssl_waitAcknowledge(channel) == IfxHssl_Hssl_Status_error)
        {
            return IfxHssl_Hssl_Status_error;
        }
    }

    /* memory count into target reload count register on target device */
    IfxHssl_Hssl_singleFrameRequest(channel, IfxHssl_Hssl_FrameRequest_writeFrame, (uint32)&channel->hssl->TS.FC, count, IfxHssl_DataLength_16bit);

    while (IfxHssl_Hssl_waitAcknowledge(channel) != IfxHssl_Hssl_Status_ok)
    {
        if (IfxHssl_Hssl_waitAcknowledge(channel) == IfxHssl_Hssl_Status_error)
        {
            return IfxHssl_Hssl_Status_error;
        }
    }

    /* incase of transfers between two different devices (loopback off) */
    if (!channel->loopBack)
    {
        /* Get the target configuration */
        IfxHssl_Hssl_read(channel, (uint32)&channel->hssl->CFG, IfxHssl_DataLength_32bit);

        while (IfxHssl_Hssl_waitAcknowledge(channel) != IfxHssl_Hssl_Status_ok)
        {
            if (IfxHssl_Hssl_waitAcknowledge(channel) == IfxHssl_Hssl_Status_error)
            {
                return IfxHssl_Hssl_Status_error;
            }
        }

        /* Check if the target streaming is enabled */
        if ((IfxHssl_Hssl_getReadData(channel) & (0x00070100)) != 0x00070100)
        {
            /* enable streaming mode (single) of channel 2 on target device */
            IfxHssl_Hssl_singleFrameRequest(channel, IfxHssl_Hssl_FrameRequest_writeFrame, (uint32)&channel->hssl->CFG, 0x00070100, IfxHssl_DataLength_32bit);

            while (IfxHssl_Hssl_waitAcknowledge(channel) != IfxHssl_Hssl_Status_ok)
            {
                if (IfxHssl_Hssl_waitAcknowledge(channel) == IfxHssl_Hssl_Status_error)
                {
                    return IfxHssl_Hssl_Status_error;
                }
            }
        }

        /* enable streaming on target device */
        IfxHssl_Hssl_singleFrameRequest(channel, IfxHssl_Hssl_FrameRequest_writeFrame, (uint32)&channel->hssl->MFLAGSSET, 0x10000000, IfxHssl_DataLength_32bit);

        while (IfxHssl_Hssl_waitAcknowledge(channel) != IfxHssl_Hssl_Status_ok)
        {
            if (IfxHssl_Hssl_waitAcknowledge(channel) == IfxHssl_Hssl_Status_error)
            {
                return IfxHssl_Hssl_Status_error;
            }
        }
    }

    channel->streamingModeOn = TRUE;    /* for waitAcknowledge function */
    /* preperation was successful */
    return IfxHssl_Hssl_Status_ok;
}


IfxHssl_Hssl_Status IfxHssl_Hssl_read(IfxHssl_Hssl_Channel *channel, uint32 address, IfxHssl_DataLength dataLength)
{
    uint32 data = 0;                                                                                                 /* not required, data will be read back */
    return IfxHssl_Hssl_singleFrameRequest(channel, IfxHssl_Hssl_FrameRequest_readFrame, address, data, dataLength); /* initiate the read request */
}


void IfxHssl_Hssl_sendControlCommand(IfxHssl_Hsct *hsct, uint8 command)
{
    Ifx_HSCT *hsctSFR = hsct->hsct;

    hsctSFR->IFCTRL.B.IFCVS = command; /* write the command into the register */
    hsctSFR->IFCTRL.B.SIFCV = 1;       /* activate the command */

    IfxHssl_Hssl_delay(hsct);          /* wait until the change happens */
}


IfxHssl_Hssl_Status IfxHssl_Hssl_singleFrameRequest(IfxHssl_Hssl_Channel *channel, IfxHssl_Hssl_FrameRequest frameRequest, uint32 address, uint32 data, IfxHssl_DataLength dataLength)
{
    Ifx_HSSL_I *hsslI = (Ifx_HSSL_I *)&channel->hssl->I[channel->channelId];

    if (channel->currentFrameRequest != IfxHssl_Hssl_FrameRequest_noAction)
    {
        return IfxHssl_Hssl_Status_busy;
    }

    hsslI->ICON.B.DATLEN = dataLength;               /* 0x2 -> word size */
    hsslI->ICON.B.TOREL  = 0xff;                     /* max reload value */

    switch (frameRequest)
    {
    case IfxHssl_Hssl_FrameRequest_readFrame:
        hsslI->ICON.B.RWT = IfxHssl_Command_readFrame;
        hsslI->IRWA.U     = address;
        break;
    case IfxHssl_Hssl_FrameRequest_writeFrame:
        hsslI->ICON.B.RWT = IfxHssl_Command_writeFrame;
        hsslI->IWD.U      = data;
        hsslI->IRWA.U     = address;
        break;
    case IfxHssl_Hssl_FrameRequest_triggerFrame:
        hsslI->ICON.B.RWT = IfxHssl_Command_triggerFrame;
        hsslI->IWD.U      = data;    /* dummy */
        hsslI->IRWA.U     = address; /* dummy */
        break;
    case IfxHssl_Hssl_FrameRequest_readId:
        /* request an ID frame  */
        hsslI->ICON.B.IDQ = 1;
        break;
    default:
        /* invalid request */
        return IfxHssl_Hssl_Status_error;
    }

    channel->currentFrameRequest = frameRequest;

    return IfxHssl_Hssl_Status_ok;
}


IfxHssl_Hssl_Status IfxHssl_Hssl_waitAcknowledge(IfxHssl_Hssl_Channel *channel)
{
    uint32            requestType = channel->currentFrameRequest;
    IfxHssl_ChannelId channelId   = channel->channelId;

    if ((channelId == IfxHssl_ChannelId_2) && (channel->hssl->CFG.B.SCM == 1))
    {
        while (channel->hssl->MFLAGS.B.ISB)
        {
            /* transfer in progress */
        }
    }
    else
    {
        if (channel->currentFrameRequest == IfxHssl_Hssl_FrameRequest_writeFrame)
        {
            requestType = 1;
        }

        /* expect a read frame when requestType == IfxHssl_Hssl_FrameRequest_readId */
        if ((channel->currentFrameRequest == IfxHssl_Hssl_FrameRequest_readFrame) || (channel->currentFrameRequest == IfxHssl_Hssl_FrameRequest_readId))
        {
            requestType = 2;
        }

        if (channel->currentFrameRequest == IfxHssl_Hssl_FrameRequest_triggerFrame)
        {
            requestType = 3;
        }

        uint32 qFlags               = channel->hssl->QFLAGS.U;
        uint32 mFlags               = channel->hssl->MFLAGS.U;
        uint32 acknwoledgeFlagsMask = ((requestType << (16 + (channel->channelId * 2))) | (1 << channel->channelId));
        uint32 errorFlagsMask       = ((0x03E00000) | (4369 << channel->channelId)); /* all the possible errors */

        if (channel->hssl->I[channelId].ICON.B.BSY == 1)
        {
            return IfxHssl_Hssl_Status_busy;
        }

        if (qFlags & acknwoledgeFlagsMask)     /* transfer in progress? */
        {
            return IfxHssl_Hssl_Status_busy;   /* return busy status in case of no error */
        }

        if (mFlags & errorFlagsMask)           /* check for errors */
        {
            channel->currentFrameRequest = IfxHssl_Hssl_FrameRequest_noAction;
            return IfxHssl_Hssl_Status_error;  /* return error status in case of an error */
        }

        /* transfer is finished */
        channel->currentFrameRequest = IfxHssl_Hssl_FrameRequest_noAction;
    }

    return IfxHssl_Hssl_Status_ok;
}


IfxHssl_Hssl_Status IfxHssl_Hssl_write(IfxHssl_Hssl_Channel *channel, uint32 address, uint32 data, IfxHssl_DataLength dataLength)
{
    return IfxHssl_Hssl_singleFrameRequest(channel, IfxHssl_Hssl_FrameRequest_writeFrame, address, data, dataLength);
}


IfxHssl_Hssl_Status IfxHssl_Hssl_writeStream(IfxHssl_Hssl *hssl, uint32 *data, Ifx_SizeT count)
{
    Ifx_HSSL             *hsslSFR       = hssl->hssl;
    Ifx_HSSL_IS          *hsslIS        = (Ifx_HSSL_IS *)&hsslSFR->IS;
    IfxHssl_StreamingMode streamingMode = IfxHssl_StreamingMode_single;

    /* single memory block streaming */
    hsslIS->SA[0].U                              = (uint32)data;  /* initiator start address to memeroy block 0 */

    hsslIS->FC.B.RELCOUNT                        = count;         /* memory count into initiator reload count register */

    hsslSFR->CFG.B.SCM                           = 1;             /* enable streaming mode of channel 2 on the initiator */
    hsslSFR->CFG.B.SMT                           = streamingMode; /* set transmitter streaming mode ( single / continuous ) on the initiator */
    hsslSFR->CFG.B.SMR                           = streamingMode; /* set receiver streaming mode ( single / continuous ) on the initiator */
    /* streaming is supported only on IfxHssl_ChannelId_2 */
    hsslSFR->I[IfxHssl_ChannelId_2].ICON.B.TOREL = 0xff;          /* set the transmitter reload value to 0xff.*/

    /* incase of transfers within the device(loopback on) */
    if (hssl->loopBack)
    {
        hsslSFR->MFLAGSSET.B.TSES = 1; /* enable target */
    }

    /* initiate the transfer */
    hsslSFR->MFLAGSSET.B.ISBS = 1;

    /* streaming started */
    return IfxHssl_Hssl_Status_ok;
}
