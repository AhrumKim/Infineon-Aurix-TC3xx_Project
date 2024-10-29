/**
 * \file IfxPort_cfg.h
 * \brief PORT on-chip implementation data
 * \ingroup IfxLld_Port
 *
 * \version iLLD_1_0_1_17_0
 * \copyright Copyright (c) 2018 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Port PORTS
 * \ingroup IfxLld
 * \defgroup IfxLld_Port_Impl Implementation
 * \ingroup IfxLld_Port
 * \defgroup IfxLld_Port_Std Standard Driver
 * \ingroup IfxLld_Port
 */

#ifndef IFXPORT_CFG_H
#define IFXPORT_CFG_H 1

/******************************************************************************/
/*----------------------------------Includes----------------------------------*/
/******************************************************************************/

#include "Cpu/Std/IfxCpu_Intrinsics.h"
#include "IfxPort_reg.h"

/******************************************************************************/
/*-----------------------------------Macros-----------------------------------*/
/******************************************************************************/

/** \brief Port count              \ingroup IfxLld_port_cfg
 */
#define IFXPORT_NUM_MODULES        (21)

#define IFXPORT_OUTOUTFEATURE_NONE (0xFFFFFFFF)

/******************************************************************************/
/*-------------------------------Enumerations---------------------------------*/
/******************************************************************************/

/** \brief List of the available Port resources
 */
typedef enum
{
    IfxPort_Index_00   = 0,  /**< \brief PORT 00 */
    IfxPort_Index_01   = 1,  /**< \brief PORT 01 */
    IfxPort_Index_02   = 2,  /**< \brief PORT 02 */
    IfxPort_Index_10   = 10, /**< \brief PORT 10 */
    IfxPort_Index_11   = 11, /**< \brief PORT 11 */
    IfxPort_Index_12   = 12, /**< \brief PORT 12 */
    IfxPort_Index_13   = 13, /**< \brief PORT 13 */
    IfxPort_Index_14   = 14, /**< \brief PORT 14 */
    IfxPort_Index_15   = 15, /**< \brief PORT 15 */
    IfxPort_Index_20   = 20, /**< \brief PORT 20 */
    IfxPort_Index_21   = 21, /**< \brief PORT 21 */
    IfxPort_Index_22   = 22, /**< \brief PORT 22 */
    IfxPort_Index_23   = 23, /**< \brief PORT 23 */
    IfxPort_Index_24   = 24, /**< \brief PORT 24 */
    IfxPort_Index_25   = 25, /**< \brief PORT 25 */
    IfxPort_Index_26   = 26, /**< \brief PORT 26 */
    IfxPort_Index_30   = 30, /**< \brief PORT 30 */
    IfxPort_Index_31   = 31, /**< \brief PORT 31 */
    IfxPort_Index_32   = 32, /**< \brief PORT 32 */
    IfxPort_Index_33   = 33, /**< \brief PORT 33 */
    IfxPort_Index_34   = 34, /**< \brief PORT 34 */
    IfxPort_Index_none = -1  /**< \brief none */
} IfxPort_Index;

/******************************************************************************/
/*-----------------------------Data Structures--------------------------------*/
/******************************************************************************/

/** \brief used by IfxPort_Esr_Masks table
 */
typedef struct
{
    Ifx_P *port;
    uint16 masks;
} IfxPort_Esr_Masks;

/******************************************************************************/
/*-------------------Global Exported Variables/Constants----------------------*/
/******************************************************************************/

IFX_EXTERN IFX_CONST IfxPort_Esr_Masks  IfxPort_cfg_esrMasks[IFXPORT_NUM_MODULES];

IFX_EXTERN IFX_CONST IfxModule_IndexMap IfxPort_cfg_indexMap[IFXPORT_NUM_MODULES];

#endif /* IFXPORT_CFG_H */
