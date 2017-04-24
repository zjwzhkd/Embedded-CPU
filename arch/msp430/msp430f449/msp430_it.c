/*******************************************************************************
* MCU型 号: MSP430F449
* 文 件 名: msp430_it.c
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2017-04-16
* 文件说明: 中断服务函数
*******************************************************************************/

#include <io430.h>

/* Basic Timer Interrupt */
#pragma vector=BASICTIMER_VECTOR
__interrupt void basic_timer_ISR(void)
{

}
