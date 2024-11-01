
/*
 * GPIO.c
 *
 *  Created on: 2024. 10. 25.
 *      Author: FM23
 */


#include "GPIO.h"  //1. GPIO.h 추가

void init_GPIO(void)
{
    /*2. GPIO 초기 설정 함수 정의*/
    /*----------out--------*/
   IfxPort_setPinModeOutput(PORT_005,IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // @suppress("Symbol is not resolved")
   /* RGB 센서 초기 설정 함수 정의 */
   //IfxPort_setPinModeOutput(PORT_Red,IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Red LED // @suppress("Symbol is not resolved")
   //IfxPort_setPinModeOutput(PORT_Green,IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Green LED // @suppress("Symbol is not resolved")
   //IfxPort_setPinModeOutput(PORT_Blue,IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Blue LED // @suppress("Symbol is not resolved")


   /*---------in--------*/
   IfxPort_setPinModeInput(PORT_020,IfxPort_InputMode_pullDown); // Encoder A // @suppress("Symbol is not resolved")
   IfxPort_setPinModeInput(PORT_021,IfxPort_InputMode_pullDown); // Encoder B // @suppress("Symbol is not resolved")

}
