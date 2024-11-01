/*
 * ADC.c
 *
 *  Created on: 2024. 10. 28.
 *      Author: FM23
 */


#include "ADC.h"
#include "STM.h"
#include "GPIO.h"

/*****1. init_ADC_Group ****/


void init_ADC_Group(void)
{
    IfxVadc_Adc_Config     adcConf; /* Define a configuration structure for the VADC module */
    IfxVadc_Adc_initModuleConfig(&adcConf, &MODULE_VADC); /* adcConf 값을 디폴트 값(MODULE_VADC)으로 초기화 */
    IfxVadc_Adc_initModule(&Vadc, &adcConf);    /* Vadc를 adcConf 값으로 초기화 */

    IfxVadc_Adc_GroupConfig  adcGroupConf;   /*Define a configuration structure for the VADC group */
    IfxVadc_Adc_initGroupConfig(&adcGroupConf, &Vadc); /* adc 그룹 구조체 초기화 및 Vadc 값 반영 */

    adcGroupConf.groupId = IfxVadc_GroupId_4;     /* Select the group */
    adcGroupConf.master = adcGroupConf.groupId;    /* Select the master group */

    adcGroupConf.arbiter.requestSlotScanEnabled = TRUE;   /* Enable scan source */
    adcGroupConf.scanRequest.autoscanEnabled = TRUE; /*Enable auto scan mode */

    adcGroupConf.scanRequest.triggerConfig.gatingMode = IfxVadc_GatingMode_always; /* 특정  트리거 조건 없이 항상 변환 수행 */

    IfxVadc_Adc_initGroup(&adcGroup4, &adcGroupConf); /* adc 그룹 설정 값 반영 */
}


/*****2. init_ADC_G4_SingleCh ****/
void init_ADC_G4_SingleCh(uint8 Channel)
{
    IfxVadc_Adc_ChannelConfig adcChannelConfigInfo;
    uint32 ulTemp = ((uint32)1u <<Channel);

    IfxVadc_Adc_initChannelConfig(&adcChannelConfigInfo, &adcGroup4); /*Fill it with default values */

    adcChannelConfigInfo.channelId = (IfxVadc_ChannelId)Channel; /*Select the Channel ID */
    adcChannelConfigInfo.resultRegister = (IfxVadc_ChannelResult)(Channel); /* Use dedicated result register */

    /* Initialize the channel */
    IfxVadc_Adc_initChannel(&adcG4Channel[Channel], &adcChannelConfigInfo); /* 채널 초기화 */

    /*Add the channel to the scan sequence */
    IfxVadc_Adc_setScan(&adcGroup4, ulTemp, ulTemp);  /* the background scan sequence. */

}

/*****3. init_ADC_G4_Channel ****/
void init_ADC_G4_Channel(void)
{
    init_ADC_G4_SingleCh(ADC_G4_CH0); /* 각 채널 초기화 */
    init_ADC_G4_SingleCh(ADC_G4_CH1);
    init_ADC_G4_SingleCh(ADC_G4_CH2);
    init_ADC_G4_SingleCh(ADC_G4_CH3);
    init_ADC_G4_SingleCh(ADC_G4_CH4);
    init_ADC_G4_SingleCh(ADC_G4_CH5);
    init_ADC_G4_SingleCh(ADC_G4_CH6);
    init_ADC_G4_SingleCh(ADC_G4_CH7);

    IfxVadc_Adc_startScan(&adcGroup4);
}

/*****4. ADC_G4_GetData ****/
void ADC_G4_GetData(void)
{
    Ifx_VADC_RES ADC_result; /*변환 결과 값 구조체 선언*/

    uint8 ch;
    for(ch = ADC_G4_CH0; ch < ADC_G4_MAX; ch++)
    {
        do{
            ADC_result = IfxVadc_Adc_getResult(&adcG4Channel[ch]); /*결과 값 가져오기*/
        }while(!ADC_result.B.VF);

        ADC_G4_RAWDATA[ch]=ADC_result.B.RESULT;   /*결과 값 저장*/
        }
    IfxVadc_Adc_startScan(&adcGroup4);
 }

/*****5. ADC_Read_Task ****/
/*void ADC_Read_Task(void)
{
    uint32 lastTime = IfxStm_getTime(&MODULE_P10,1); // 현재 시간 저장

    while (1) {
        uint32 currentTime = IfxStm_getTime(&MODULE_STM0); // 현재 시간 가져오기

        // 마지막 읽기 시간과 현재 시간 차이가 100ms 이상인지 확인
        if ((currentTime - lastTime) >= (100 * (IfxStm_getFrequency(&MODULE_STM0) / 1000))) {
            ADC_G4_GetData(); // ADC 데이터 읽기
            lastTime = currentTime; // 마지막 읽기 시간을 현재 시간으로 업데이트
        }
    }
}
*/
