/*
 * GPIO.c
 *
 *  Created on: 2024. 10. 25.
 *      Author: FM22
 */
#include "GPIO.h"



void init_GPIO(void)
{
    IfxPort_setPinModeOutput(PORT_005, IfxPort_OutputMode_pushPull, IfxPort_OutputIdx_general);
}


void LED_toggle(void){
    int i = 0;
    int j = 0; /*10^7*/
    for (i = 0; i < b; i++){
        IfxPort_setPinHigh(PORT_005);
    }
    for (j = 0; j < b; j++){
        IfxPort_setPinLow(PORT_005);
    }
}

void Good_LED_toggle(void){
    if(a>b){
        a = 0;
        IfxPort_togglePin(PORT_005);
    }
    a += 0.0001;    /*(0.0001*10^5 = 10)*/
}


