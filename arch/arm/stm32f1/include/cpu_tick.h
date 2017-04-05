/*******************************************************************************
* MCU型 号: STM32F1XX
* 文 件 名: cpu_tick.h
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2016-08-23
* 文件说明: CPU节拍实现以及时间管理
*******************************************************************************/

#ifndef __CPU_TICK_H
#define __CPU_TICK_H

/* 头文件 --------------------------------------------------------------------*/
#include "cpu_port.h"

/* 节拍转换宏 ----------------------------------------------------------------*/
#define CPU_MS_TO_TICK(nms)     ( (tick_t)((uint32_t)(nms)*CPU_TICK_HZ/1000) )
#define CPU_TICK_TO_MS(ntick)   ( (uint32_t)(ntick)*1000/CPU_TICK_HZ )

/* 接口函数 ------------------------------------------------------------------*/
void cpu_TickInit(void);
void cpu_DelayUs(uint32_t nus);
void cpu_DelayMs(uint16_t nms);

#endif  /* __CPU_TICK_H */
