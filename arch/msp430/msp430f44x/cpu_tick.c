/*******************************************************************************
* MCU型 号: MSP430F44X
* 文 件 名: cpu_tick.c
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2017-04-16
* 文件说明: CPU节拍实现以及时间管理
*******************************************************************************/

#include "cpu_tick.h"
/*******************************************************************************

                                    节拍函数

*******************************************************************************/
void cpu_TickInit(void)
{
    //BTCTL = BT_fCLK2_DIV256;
    BTCTL = BT_ADLY_64;
    IE2 |= BTIE;
}