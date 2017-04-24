/*******************************************************************************
* MCU型 号: MSP430F449
* 文 件 名: cpu_config.h
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2017-04-16
* 文件说明: CPU配置文件
*******************************************************************************/

#ifndef __CPU_CONFIG_H
#define __CPU_CONFIG_H

/* 参数配置 ------------------------------------------------------------------*/
#define CPU_ACLK_HZ         ( (uint32_t) 32768 )    /* MSP430 ACLK频率(Hz)    */
#define CPU_MCLK_HZ         ( (uint32_t) 3997696 )  /* MSP430 MCLK频率(Hz)    */
#define CPU_SMCLK_HZ        ( (uint32_t) 3997696 )  /* MSP430 SMCLK频率(Hz)   */
#define CPU_FREQ_HZ         ( CPU_MCLK_HZ )         /* CPU运行频率(Hz)        */
#define CPU_TIMER_HZ        ( CPU_ACLK_HZ )         /* CPU节拍定时器频率(Hz)  */
#define CPU_TICK_HZ         ( (uint32_t) 128 )      /* CPU节拍频率(Hz)        */

/* 功能配置 ------------------------------------------------------------------*/
#define CPU_ASSERT_EN       ( 1 )                   /* 调试断言功能使能       */
#define CPU_PRINTF_EN       ( 1 )                   /* 调试输出功能使能       */
#define CPU_16BIT_TICK_EN   ( 1 )                   /* 16bit节拍类型使能      */

#endif  /* __CPU_CONFIG_H */
