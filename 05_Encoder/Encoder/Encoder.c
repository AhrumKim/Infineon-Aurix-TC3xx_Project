/*
 * Encoder.c
 *
 *  Created on: 2024. 10. 28.
 *      Author: FM23
 */

#include "Encoder.h"
#include "GPIO.h"

void Encoder(void)
{
     /* A,B 상 현재 값 받아오기(0 or 1)*/

    uint8 A = IfxPort_getPinState(PORT_020);
    uint8 B = IfxPort_getPinState(PORT_021);

    uint8 state = 0;

    /* A,B 상을 통해 현재 상태 계산*/

    if (A==0 && B ==0){state=0;}
    else if(A==1 && B==0){state=1;}
    else if(A==1 && B==1){state=2;}
    else if(A==0&&B==1){state=3;}


    /*현재와 이전 상태 차이를 통해 ㅓㄹ스 카운트 및 방향 계산*/

    if(state-state_old==1 || state-state_old==-3){encoderCNT++; encoderDir = 1;}
    else if(state-state_old==-1 || state-state_old==3){encoderCNT--; encoderDir=-1;}

    theta = encoderCNT*0.01*0.25*360; /* 한바퀴 100펄스(0.01), 4채배(0.25)*/

    state_old = state; //펄스 카운트 -> 각도 변환 * 각 모터에 맞게 값 변경 필요

}
