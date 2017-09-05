/*******************************************************************************
* MCU型 号: STM32F1XX
* 文 件 名: cpu_tick.c
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2016-08-23
* 文件说明: CPU节拍实现以及时间管理
*******************************************************************************/

#include "cpu_tick.h"

/*******************************************************************************

                                    节拍函数

*******************************************************************************/
/* CPU节拍以及时间管理初始化 */
void cpu_TickInit(void)
{
    /*初始化SysTick*/
    SysTick_Config(CPU_TIMER_HZ/CPU_TICK_HZ);
}

/*******************************************************************************

                                    时间管理

*******************************************************************************/
/**
 * CPU频率周期延时函数
 *
 * @param ncycle: 周期数
 */
void cpu_DelayCycle(uint32_t ncycle)
{
uint32_t totalCnt;
uint32_t tnew, told, tcnt;
uint32_t reload = SysTick->LOAD+1;

    totalCnt = ncycle;
    tcnt = 0;
    told = SysTick->VAL;
    for ( ;; )
    {
        tnew = SysTick->VAL;
        if (tnew != told)
        {
            if (tnew<told) tcnt += told - tnew;
            else tcnt += reload + told - tnew;
            told = tnew;
            if (tcnt>=totalCnt) break;
        }
    }
}
