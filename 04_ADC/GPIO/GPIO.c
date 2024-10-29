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
   IfxPort_setPinModeOutput(PORT_005,IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
   /* RGB 센서 초기 설정 함수 정의 */
   IfxPort_setPinModeOutput(PORT_Red,IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Red LED
   IfxPort_setPinModeOutput(PORT_Green,IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Green LED
   IfxPort_setPinModeOutput(PORT_Blue,IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general); // Blue LED



}
