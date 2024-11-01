/*
 * GPIO.h
 *
 *  Created on: 2024. 10. 25.
 *      Author: FM23
 */

#ifndef GPIO_GPIO_H_
#define GPIO_GPIO_H_

/* Header_275.h 추가 */
#include "Header_275.h"

#ifdef USE_GLOBAL_H
#define Global
#else
#define Global extern
#endif

/***** Pin setting *****/

//1. 사용할 Pin 정의 (0번 모듈: 5번 포트)
#define PORT_005 &MODULE_P10,2     /*ShieldBuddy P10.2*/ /*LiteKit P00.5*/
#define PORT_Red &MODULE_P10,1  // Red LED
#define PORT_Green &MODULE_P10,3 // Green LED
#define PORT_Blue &MODULE_P10,2 // Blue LED


//2. GPIO 초기 설정 함수 선언
Global void init_GPIO(void);

#endif /* GPIO_GPIO_H_ */
