/*
 * ADC.h
 *
 *  Created on: 2024. 10. 28.
 *      Author: FM23
 */

#ifndef ADC_ADC_H_
#define ADC_ADC_H_

#include "Header_275.h"

#ifdef USE_GLOBAL_H
#define Global
#else
#define Global extern
#endif


typedef enum
{
    ADC_G4_CH0 = 0u, //0
    ADC_G4_CH1 , //1
    ADC_G4_CH2 , //2
    ADC_G4_CH3 , //3
    ADC_G4_CH4 , //4
    ADC_G4_CH5 , //5
    ADC_G4_CH6 , //6
    ADC_G4_CH7,  //7
    ADC_G4_MAX  //8
}ADC4;

Global IfxVadc_Adc          Vadc;                     //ADC 구조체 선언
Global IfxVadc_Adc_Group    adcGroup4;                //ADC Group 구조체 선언
Global IfxVadc_Adc_Channel  adcG4Channel[ADC_G4_MAX]; //ADC Channel 구조체 선언
Global IfxVadc_Adc          Vadc;

Global uint16 ADC_G4_RAWDATA[ADC_G4_MAX]; // 변환 값을 저장할 배열 선언

Global void init_ADC_Group(void);  //ADC Group 초기 세팅 함수

void init_ADC_G4_SingleCH(uint8 Channel); //ADC 단일 채널 초기 세팅 함수

Global void init_ADC_G4_Channel(void); //ADC 채널 초기 세팅 함수

void ADC_G4_GetData(void);             //ADC 변환 값 가져오는 함수

void ADC_Read_Task(void); //ADC 변환 값을 100ms 마다 가져오는 함수

#endif /* ADC_ADC_H_ */
