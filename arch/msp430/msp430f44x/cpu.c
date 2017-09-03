/*******************************************************************************
* MCU型 号: MSP430F44X
* 文 件 名: cpu.c
* 创 建 者: Keda Huang
* 版    本: V1.0
* 创建日期: 2017-04-16
* 文件说明: CPU底层实现
*******************************************************************************/

#include "cpu.h"

static void prvSystemClockConfig(void);
/*******************************************************************************

                                    接口函数

*******************************************************************************/
/* CPU初始化 */
void cpu_Init(void)
{
    prvSystemClockConfig();
    cpu_TickInit();
}

/*******************************************************************************

                                    内部函数

*******************************************************************************/
/* 系统时钟初始化 */
static void prvSystemClockConfig(void)
{
    /* FLL+ Control Register 0
     * 7        6       5:4     3       2       1       0
     * DCOPLUS  XTS_FLL XCAPxPF XT2OF   XT1OF   LFOF    DCOF
     */
    FLL_CTL0 = XCAP18PF;
    /* FLL+ Control Register 1
     * 7    6           5       4:3     2       1:0
     * NC   SMCLKOFF    XT2OFF  SELMx   SELS    FLL_DIVx
     */
    FLL_CTL1 = XT2OFF;
    /* System Clock Frequency Integrator Register 0
     * 7:6      5:2     1:0
     * FLLDx    FN_x    MODx(LSBs)
     */
    SCFI0 = FN4 + FLLD_2;
    /* System Clock Control Register
     * 7        6:0
     * SCFQ_M   N
     */
    SCFQCTL = (CPU_MCLK_HZ/CPU_ACLK_HZ-1) & 0x7F;

    do
    {
        IFG1 &= ~OFIFG;
        cpu_DelayMs(100);
    }
    while (IFG1 & OFIFG);
}
