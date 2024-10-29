/**
 * \file IfxEth_PinMap.h
 * \brief ETH I/O map
 * \ingroup IfxLld_Eth
 *
 * \version iLLD_1_0_1_17_0
 * \copyright Copyright (c) 2013 Infineon Technologies AG. All rights reserved.
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
 * \defgroup IfxLld_Eth_pinmap ETH Pin Mapping
 * \ingroup IfxLld_Eth
 */

#ifndef IFXETH_PINMAP_H
#define IFXETH_PINMAP_H

#include <IfxEth_reg.h>
#include <_Impl/IfxEth_cfg.h>
#include <Port/Std/IfxPort.h>

/** \addtogroup IfxLld_Eth_pinmap
 * \{ */

/** \brief CRS pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Crs_In;

/** \brief CRSDV pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Crsdv_In;

/** \brief RXDV pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Rxdv_In;

/** \brief REFCLK pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Refclk_In;

/** \brief RXCLK pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Rxclk_In;

/** \brief TXCLK pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Txclk_In;

/** \brief RXD pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Rxd_In;

/** \brief COL pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Col_In;

/** \brief MDC pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEth_Mdc_Out;

/** \brief MDIO pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         inSelect; /**< \brief Input multiplexer value */
    IfxPort_OutputIdx outSelect;/**< \brief Port control code */
} IfxEth_Mdio_InOut;

/** \brief TXD pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEth_Txd_Out;

/** \brief TXEN pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEth_Txen_Out;

/** \brief TXER pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    IfxPort_OutputIdx select;   /**< \brief Port control code */
} IfxEth_Txer_Out;

/** \brief RXER pin mapping structure */
typedef const struct
{
    Ifx_ETH*          module;   /**< \brief Base address */
    IfxPort_Pin       pin;      /**< \brief Port pin */
    Ifx_RxSel         select;   /**< \brief Input multiplexer value */
} IfxEth_Rxer_In;

IFX_EXTERN IfxEth_Col_In IfxEth_COL_P11_15_IN;  /**< \brief ETH_COL: ETH input */
IFX_EXTERN IfxEth_Crs_In IfxEth_CRSA_P11_14_IN;  /**< \brief ETH_CRSA: ETH input */
IFX_EXTERN IfxEth_Crs_In IfxEth_CRSB_P11_11_IN;  /**< \brief ETH_CRSB: ETH input */
IFX_EXTERN IfxEth_Crsdv_In IfxEth_CRSDVA_P11_11_IN;  /**< \brief ETH_CRSDVA: ETH input */
IFX_EXTERN IfxEth_Crsdv_In IfxEth_CRSDVB_P11_14_IN;  /**< \brief ETH_CRSDVB: ETH input */
IFX_EXTERN IfxEth_Mdc_Out IfxEth_MDC_P02_8_OUT;  /**< \brief ETH_MDC: ETH output */
IFX_EXTERN IfxEth_Mdc_Out IfxEth_MDC_P12_0_OUT;  /**< \brief ETH_MDC: ETH output */
IFX_EXTERN IfxEth_Mdc_Out IfxEth_MDC_P21_0_OUT;  /**< \brief ETH_MDC: ETH output */
IFX_EXTERN IfxEth_Mdc_Out IfxEth_MDC_P21_2_OUT;  /**< \brief ETH_MDC: ETH output */
IFX_EXTERN IfxEth_Mdio_InOut IfxEth_MDIOA_P00_0_INOUT;  /**< \brief ETH_MDIOA: ETH input/output */
IFX_EXTERN IfxEth_Mdio_InOut IfxEth_MDIOC_P12_1_INOUT;  /**< \brief ETH_MDIOC: ETH input/output */
IFX_EXTERN IfxEth_Mdio_InOut IfxEth_MDIOD_P21_3_INOUT;  /**< \brief ETH_MDIOD: ETH input/output */
IFX_EXTERN IfxEth_Mdio_InOut IfxEth_MDIO_P21_1_INOUT;  /**< \brief ETH_MDIO: ETH output    (Not for production purposes) */
IFX_EXTERN IfxEth_Refclk_In IfxEth_REFCLK_P11_12_IN;  /**< \brief ETH_REFCLK: ETH input */
IFX_EXTERN IfxEth_Rxclk_In IfxEth_RXCLKA_P11_12_IN;  /**< \brief ETH_RXCLKA: ETH input   (Not for productive purposes) */
IFX_EXTERN IfxEth_Rxclk_In IfxEth_RXCLKB_P11_4_IN;  /**< \brief ETH_RXCLKB: ETH input */
IFX_EXTERN IfxEth_Rxclk_In IfxEth_RXCLKC_P12_0_IN;  /**< \brief ETH_RXCLKC: ETH input */
IFX_EXTERN IfxEth_Rxd_In IfxEth_RXD0_P11_10_IN;  /**< \brief ETH_RXD0: ETH input */
IFX_EXTERN IfxEth_Rxd_In IfxEth_RXD1_P11_9_IN;  /**< \brief ETH_RXD1: ETH input */
IFX_EXTERN IfxEth_Rxd_In IfxEth_RXD2_P11_8_IN;  /**< \brief ETH_RXD2: ETH input */
IFX_EXTERN IfxEth_Rxd_In IfxEth_RXD3_P11_7_IN;  /**< \brief ETH_RXD3: ETH input */
IFX_EXTERN IfxEth_Rxdv_In IfxEth_RXDVA_P11_11_IN;  /**< \brief ETH_RXDVA: ETH input */
IFX_EXTERN IfxEth_Rxdv_In IfxEth_RXDVB_P11_14_IN;  /**< \brief ETH_RXDVB: ETH input */
IFX_EXTERN IfxEth_Rxer_In IfxEth_RXERA_P11_13_IN;  /**< \brief ETH_RXERA: ETH input */
IFX_EXTERN IfxEth_Rxer_In IfxEth_RXERB_P21_7_IN;  /**< \brief ETH_RXERB: ETH input */
IFX_EXTERN IfxEth_Txclk_In IfxEth_TXCLKA_P11_5_IN;  /**< \brief ETH_TXCLKA: ETH input */
IFX_EXTERN IfxEth_Txclk_In IfxEth_TXCLKB_P11_12_IN;  /**< \brief ETH_TXCLKB: ETH input   (Not for productive purposes) */
IFX_EXTERN IfxEth_Txd_Out IfxEth_TXD0_P11_3_OUT;  /**< \brief ETH_TXD0: ETH output */
IFX_EXTERN IfxEth_Txd_Out IfxEth_TXD1_P11_2_OUT;  /**< \brief ETH_TXD1: ETH output */
IFX_EXTERN IfxEth_Txd_Out IfxEth_TXD2_P11_1_OUT;  /**< \brief ETH_TXD2: ETH output */
IFX_EXTERN IfxEth_Txd_Out IfxEth_TXD3_P11_0_OUT;  /**< \brief ETH_TXD3: ETH output */
IFX_EXTERN IfxEth_Txen_Out IfxEth_TXEN_P11_6_OUT;  /**< \brief ETH_TXEN: ETH output */
IFX_EXTERN IfxEth_Txer_Out IfxEth_TXER_P11_4_OUT;  /**< \brief ETH_TXER: ETH output */

/** \brief Table dimensions */
#define IFXETH_PINMAP_NUM_MODULES 1
#define IFXETH_PINMAP_COL_IN_NUM_ITEMS 1
#define IFXETH_PINMAP_CRS_IN_NUM_ITEMS 2
#define IFXETH_PINMAP_CRSDV_IN_NUM_ITEMS 2
#define IFXETH_PINMAP_MDC_OUT_NUM_ITEMS 4
#define IFXETH_PINMAP_MDIO_INOUT_NUM_ITEMS 7
#define IFXETH_PINMAP_REFCLK_IN_NUM_ITEMS 1
#define IFXETH_PINMAP_RXCLK_IN_NUM_ITEMS 3
#define IFXETH_PINMAP_RXD_IN_NUM_ITEMS 1
#define IFXETH_PINMAP_RXDV_IN_NUM_ITEMS 2
#define IFXETH_PINMAP_RXER_IN_NUM_ITEMS 2
#define IFXETH_PINMAP_TXCLK_IN_NUM_ITEMS 2
#define IFXETH_PINMAP_TXD_OUT_NUM_ITEMS 4
#define IFXETH_PINMAP_TXEN_OUT_NUM_ITEMS 1
#define IFXETH_PINMAP_TXER_OUT_NUM_ITEMS 1


/** \brief IfxEth_Col_In table */
IFX_EXTERN const IfxEth_Col_In *IfxEth_Col_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_COL_IN_NUM_ITEMS];

/** \brief IfxEth_Crs_In table */
IFX_EXTERN const IfxEth_Crs_In *IfxEth_Crs_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_CRS_IN_NUM_ITEMS];

/** \brief IfxEth_Crsdv_In table */
IFX_EXTERN const IfxEth_Crsdv_In *IfxEth_Crsdv_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_CRSDV_IN_NUM_ITEMS];

/** \brief IfxEth_Mdc_Out table */
IFX_EXTERN const IfxEth_Mdc_Out *IfxEth_Mdc_Out_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_MDC_OUT_NUM_ITEMS];

/** \brief IfxEth_Mdio_InOut table */
IFX_EXTERN const IfxEth_Mdio_InOut *IfxEth_Mdio_InOut_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_MDIO_INOUT_NUM_ITEMS];

/** \brief IfxEth_Refclk_In table */
IFX_EXTERN const IfxEth_Refclk_In *IfxEth_Refclk_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_REFCLK_IN_NUM_ITEMS];

/** \brief IfxEth_Rxclk_In table */
IFX_EXTERN const IfxEth_Rxclk_In *IfxEth_Rxclk_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_RXCLK_IN_NUM_ITEMS];

/** \brief IfxEth_Rxd_In table */
IFX_EXTERN const IfxEth_Rxd_In *IfxEth_Rxd_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_RXD_IN_NUM_ITEMS];

/** \brief IfxEth_Rxdv_In table */
IFX_EXTERN const IfxEth_Rxdv_In *IfxEth_Rxdv_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_RXDV_IN_NUM_ITEMS];

/** \brief IfxEth_Rxer_In table */
IFX_EXTERN const IfxEth_Rxer_In *IfxEth_Rxer_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_RXER_IN_NUM_ITEMS];

/** \brief IfxEth_Txclk_In table */
IFX_EXTERN const IfxEth_Txclk_In *IfxEth_Txclk_In_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_TXCLK_IN_NUM_ITEMS];

/** \brief IfxEth_Txd_Out table */
IFX_EXTERN const IfxEth_Txd_Out *IfxEth_Txd_Out_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_TXD_OUT_NUM_ITEMS];

/** \brief IfxEth_Txen_Out table */
IFX_EXTERN const IfxEth_Txen_Out *IfxEth_Txen_Out_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_TXEN_OUT_NUM_ITEMS];

/** \brief IfxEth_Txer_Out table */
IFX_EXTERN const IfxEth_Txer_Out *IfxEth_Txer_Out_pinTable[IFXETH_PINMAP_NUM_MODULES][IFXETH_PINMAP_TXER_OUT_NUM_ITEMS];

/** \} */

#endif /* IFXETH_PINMAP_H */
