/*******************************************************************************
* MCU型 号: STM8S
* 文 件 名: cpu_port.h
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2016-10-13
* 文件说明: CPU接口定义
*******************************************************************************/

#ifndef __CPU_PORT_H
#define __CPU_PORT_H

/* 头文件 --------------------------------------------------------------------*/
#include "stm8s.h"
#include "cpu_config.h"
#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

/* 架构定义 ------------------------------------------------------------------*/
/* CPU中断嵌套设置 */
/* #define CPU_INTERRUPT_NOT_NESTING */

/* CPU内存字节对齐 */
#define CPU_BYTE_ALIGNMENT              ( 1 )

/*CPU体系数据类型*/
typedef int8_t          base_t;
typedef uint8_t         ubase_t;
typedef __istate_t      cpu_t;

/* 节拍类型 ------------------------------------------------------------------*/
#if CPU_16BIT_TICK_EN
    typedef uint16_t    tick_t;
#else
    typedef uint32_t    tick_t;
#endif

/* 编译器宏 ------------------------------------------------------------------*/
/* 声明数据保存在FLASH上 */
#define FLASH_DATA
/* 声明数据保存在EEPROM上 */
#define EEPROM_DATA __eeprom
/* 静态内联函数 */
#ifndef STATIC_INLINE
    #define STATIC_INLINE static inline
#endif
/* 编译断言 */
#define COMPILE_ASSERT(EXPR)    {typedef char ASSERT_ARRAY[(EXPR) ? 1 : -1];}

/* 中断/临界区宏 -------------------------------------------------------------*/
/* 全局中断使能/禁止 */
#define CPU_EnableInterrupts()              cpu_irq_enable()
#define CPU_DisableInterrupts()             cpu_irq_disable()

/*
    CPU_EnterCritical()和CPU_ExitCritical(x),
    适用于线程函数的临界资源保护, 也可以用于中断函数的临界资源保护,
    在中断函数中推荐使用FromISR版本代替, 它针对中断进行了优化
*/
#define CPU_EnterCritical()                 cpu_irq_save()
#define CPU_ExitCritical(x)                 cpu_irq_restore(x)

/*
    CPU_EnterCriticalFromISR()和CPU_ExitCriticalFromISR(x),
    仅能用于中断函数的临界资源保护, 并且对非嵌套中断的情况进行了优化,
    禁止在线程函数中使用FromISR版本的函数
*/
#ifdef CPU_INTERRUPT_NOT_NESTING
    #define CPU_EnterCriticalFromISR()      ( 0 )
    #define CPU_ExitCriticalFromISR(x)      ( (void)(x) )
#else
    #define CPU_EnterCriticalFromISR()      cpu_irq_save()
    #define CPU_ExitCriticalFromISR(x)      cpu_irq_restore(x)
#endif

/* 调试相关宏 ----------------------------------------------------------------*/
/* 调试断言 */
#if CPU_ASSERT_EN
    #define CPU_Assert(expr)    do { if (!(expr)) {CPU_DisableInterrupts();while(1);} } while(0)
#else
    #define CPU_Assert(expr)    ((void)0)
#endif

/* 调试输出 */
#if CPU_PRINTF_EN
    #include <stdio.h>
    #define CPU_Printf(...)     printf(__VA_ARGS__)
#else
    #define CPU_Printf(...)     ((void)0)
#endif

/* 底层操作宏 ----------------------------------------------------------------*/
#define CPU_NOP()               __no_operation()

/* CPU中断管理 ---------------------------------------------------------------*/
#define cpu_irq_enable()        __enable_interrupt()
#define cpu_irq_disable()       __disable_interrupt()

STATIC_INLINE cpu_t cpu_irq_save(void)
{
cpu_t cpu_sr;

    cpu_sr = __get_interrupt_state();
    cpu_irq_disable();
    return (cpu_sr);
}
STATIC_INLINE void cpu_irq_restore(cpu_t cpu_sr)
{
    __set_interrupt_state(cpu_sr);
}

#endif  /* __CPU_PORT_H */
