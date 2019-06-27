/*******************************************************************************
* MCU型 号: STM8S
* 文 件 名: cpu_tick.c
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2016-10-13
* 文件说明: CPU节拍实现以及时间管理
*******************************************************************************/

#include "cpu_tick.h"

/*******************************************************************************

                                    节拍函数

*******************************************************************************/
/*CPU节拍以及时间管理初始化*/
void cpu_TickInit(void)
{
    /*
     * 初始化Timer4
     * CPU_TIMER_HZ = CPU_FREQ_HZ/64
     * PERIOD = CPU_TIMER_HZ/CPU_TICK_HZ-1
     * 开启UPDATE中断
     */
    TIM4_TimeBaseInit(TIM4_PRESCALER_64, CPU_TIMER_HZ/CPU_TICK_HZ-1);
    TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE);
    TIM4_Cmd(ENABLE);
}

/*******************************************************************************

                                    时间管理

*******************************************************************************/
/**
 * 定时器节拍延时函数
 *
 * @param n: 延时时间(1/CPU_TIMER_HZ)
 */
void cpu_Delay(uint32_t n)
{
uint32_t totalCnt = n, tcnt = 0;
uint8_t tnew, told, reload = TIM4->ARR + 1;

    told = TIM4->CNTR;
    for ( ;; )
    {
        tnew = TIM4->CNTR;
        if (tnew != told)
        {
            if (tnew>told) tcnt += tnew - told;
            else tcnt += reload + tnew - told;
            told = tnew;
            if (tcnt>=totalCnt) break;
        }
    }
}
