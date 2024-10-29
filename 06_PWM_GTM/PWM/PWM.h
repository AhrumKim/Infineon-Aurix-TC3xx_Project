/*
 * PWM.h
 *
 *  Created on: 2024. 10. 29.
 *      Author: FM23
 */

#ifndef PWM_PWM_H_
#define PWM_PWM_H_

#include "Header_275.h"

#ifdef USE_GLOBAL_H
#define Global
#else
#define Global extern
#endif

#define PRIORITY_GTM 200u//1. 인터럽트 우선순위 설정 변수

/*2. 타이머 및 PWM 구조체 선언*/
typedef struct
{
        IfxGtm_Tom_Timer timer;
        IfxGtm_Tom_PwmHl pwm;
        float32          duty[2];
}st_GtmTomPwmHl;

Global st_GtmTomPwmHl GtmPwmHl;

void init_Tom(void); //3.TOM 초기화 함수 선언
void init_PWM(IfxGtm_Tom_Timer_Config*timerConfig); //4. PWM 초기화 함수 선언
Global void init_GTM(void);//5. GTM 초기화 함수 선언
Global void PWM_dutyUpdate();//6. PWM duty 업데이트 함수 선언

#endif /* PWM_PWM_H_ */
