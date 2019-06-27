/*******************************************************************************
* MCU型 号: STM8S
* 文 件 名: cpu_config.h
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2016-10-13
* 文件说明: CPU配置文件
*******************************************************************************/

#ifndef __CPU_CONFIG_H
#define __CPU_CONFIG_H

/* CPU参数配置 ---------------------------------------------------------------*/
#define CPU_FREQ_HZ         ( HSE_VALUE )           /* CPU运行频率(Hz)        */
#define CPU_TIMER_HZ        ( CPU_FREQ_HZ/64 )      /* CPU节拍定时器频率(Hz)  */
#define CPU_TICK_HZ         ( (uint32_t) 500 )      /* CPU节拍频率(Hz)        */
#define CPU_BYTE_ALIGNMENT  ( 1 )                   /* CPU内存字节对齐        */

/* CPU调试配置 ---------------------------------------------------------------*/
#define CPU_ASSERT_EN       ( 1 )                   /* 调试断言功能使能       */
#define CPU_PRINTF_EN       ( 1 )                   /* 调试输出功能使能       */
#define CPU_16BIT_TICK_EN   ( 0 )                   /* 16bit节拍类型使能      */

#endif  /* __CPU_CONFIG_H */
