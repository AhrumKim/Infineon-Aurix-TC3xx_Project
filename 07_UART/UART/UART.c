/*
 * UART.c
 *
 *  Created on: 2024. 10. 29.
 *      Author: FM23
 */


#include "UART.h"


#define ASC_TX_BUFFER_SIZE      256 //버퍼 사이즈 설정 변수
#define ASC_RX_BUFFER_SIZE      256 //버퍼 사이즈 설정 변수
#define ASC_BAUDRATE            115200 //Buadrate 설정 변수
#define ISR_PRIORITY_ASCLIN_TX  8   /*Priority for interrupt ISR Transmit */
#define ISR_PRIORITY_ASCLIN_RX  4  /*Priority for interrupt ISR Receive */
#define ISR_PRIORITY_ASCLIN_ER  12  /*Priority for interrupt ISR Receive */


static IfxAsclin_Asc   g_ascHandle0;  //UART 설정 구조체 선언

/*송신/수신 데이터 버퍼 변수 선언*/
uint8 g_uartTxBuffer[ASC_TX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];
uint8 g_uartRxBuffer[ASC_RX_BUFFER_SIZE + sizeof(Ifx_Fifo) + 8];

void init_UART(void)
{
    IfxAsclin_Asc_Config ascConf; // UART config 구조체 선언

    /*Set default configurations*/
    IfxAsclin_Asc_initModuleConfig(&ascConf, &MODULE_ASCLIN3); /* Initiallize the structure with default values*/
    //구조체 디폴트 값으로 초기화

    /* Set the desired baud rate */
    ascConf.baudrate.baudrate   = ASC_BAUDRATE; /*baudrate 설정 */
    ascConf.baudrate.oversampling = IfxAsclin_OversamplingFactor_16;/* 한 비트에 몇 번 샘플링 할지(데이터 정확성 향상)*/

    /*Configure the sampling mode */
    ascConf.interrupt.txPriority  = ISR_PRIORITY_ASCLIN_TX; /* TX 인터럽트 순위 설정 */
    ascConf.interrupt.rxPriority  = ISR_PRIORITY_ASCLIN_RX;/* RX 인터럽트 순위 설정 */
    ascConf.interrupt.erPriority  = ISR_PRIORITY_ASCLIN_ER;/* 에러 인터럽트 순위 설정 */
    ascConf.interrupt.typeOfService  = IfxSrc_Tos_cpu0;    /* 인터럽트 발생 CPU 설정 */

    /*Pin configuration*/
    const IfxAsclin_Asc_Pins pins = {
            .tx  = &IfxAsclin3_TX_P15_7_OUT, /*Tx 핀 설정*/
            .txMode  = IfxPort_OutputMode_pushPull, /*Tx 핀 설정*/
            .rx  = &IfxAsclin3_RXD_P32_2_IN, /*Rx 핀 설정*/
            .rxMode  = IfxPort_InputMode_pullUp, /*Rx 핀 설정*/
            .cts  = NULL_PTR, /*CTS pin not used (clear to send)*/
            .ctsMode  = IfxPort_InputMode_pullUp,
            .rts  = NULL_PTR, /*RTS pin not used (request to send)*/
            .rtsMode  = IfxPort_OutputMode_pushPull,
            .pinDriver  = IfxPort_PadDriver_cmosAutomotiveSpeed1, /*핀 드라이버 선택*/

    };
    ascConf.pins = &pins;

    /*FIFO buffers configuration */
     ascConf.txBuffer  = g_uartTxBuffer;  /*Set the Transmission buffer*/
     ascConf.txBufferSize = ASC_TX_BUFFER_SIZE;
     ascConf.rxBuffer = g_uartRxBuffer;
     ascConf.rxBufferSize = ASC_RX_BUFFER_SIZE;

     /*Init ASCLIN module */
     IfxAsclin_Asc_initModule(&g_ascHandle0, &ascConf);


}

void out_UART0(const unsigned char chr)
{
    IfxAsclin_Asc_blockingWrite(&g_ascHandle0, chr);
}

IFX_INTERRUPT(asc0TxISR, 0 , ISR_PRIORITY_ASCLIN_TX);
void asc0TxISR(void){IfxAsclin_Asc_isrTransmit(&g_ascHandle0);}

IFX_INTERRUPT(asc0RxISR, 0 , ISR_PRIORITY_ASCLIN_RX);
void asc0RxISR(void)
{

    IfxAsclin_Asc_isrReceive(&g_ascHandle0);
    RXDATA = IfxAsclin_Asc_blockingRead(&g_ascHandle0);

    RXcnt++;
}

IFX_INTERRUPT(asc0ErrISR, 0, ISR_PRIORITY_ASCLIN_ER);
void asc0ErrISR(void){while(1);}
