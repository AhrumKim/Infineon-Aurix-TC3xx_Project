/*
 * Scheduler.c
 *
 *  Created on: 2024. 10. 28.
 *      Author: FM23
 */

#include "Scheduler.h"
#include "STM.h"

extern uint32 Scheduler1msFlag;
extern uint32 Scheduler10msFlag;
extern uint32 Scheduler100msFlag;

void AppScheduling(void)
{
    if(Scheduler1msFlag == 1)
    {
        Scheduler1msFlag = 0;
        Task1ms();
        if(Scheduler10msFlag == 1)
        {
            Scheduler10msFlag = 0;
            Task10ms();
        }
        if(Scheduler100msFlag == 1)
         {
             Scheduler100msFlag = 0;
             Task100ms();
         }
    }
}

void Task1ms(void)
{
    cnt1ms++;
    IfxPort_togglePin(&MODULE_P10,1);// Red LED
}

void Task10ms(void)
{
    cnt10ms++;
    IfxPort_togglePin(&MODULE_P10,3);// Green LED
}

void Task100ms(void)
{
    cnt100ms++;
    IfxPort_togglePin(&MODULE_P10,2);// Blue LED
}


