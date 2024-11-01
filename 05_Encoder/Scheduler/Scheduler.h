/*
 * Scheduler.h
 *
 *  Created on: 2024. 10. 28.
 *      Author: FM23
 */

#ifndef SCHEDULER_SCHEDULER_H_
#define SCHEDULER_SCHEDULER_H_

#include "Header_275.h"

#ifdef USE_GLOBAL_H
#define Global
#else
#define Global extern
#endif


//1. 각 주기마다 아래 함수 실행
Global void AppScheduling(void);
void Task1ms(void);
void Task10ms(void);
void Task100ms(void);

/* 확인용 변수*/
Global uint32 cnt1ms;
Global uint32 cnt10ms;
Global uint32 cnt100ms;

#endif /* SCHEDULER_SCHEDULER_H_ */
