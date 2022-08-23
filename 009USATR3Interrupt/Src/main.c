/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2022 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <stdio.h>

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
  #warning "FPU is not initialised, but the project is compiling for an FPU. Please initialise the FPU before use."
#endif

#define USART3_IRQ_NUM 39

int main(void)
{
	//1.) Manually pend the Pending bit of the IPSR for USART3 using IRQ Number.
    uint32_t *pIPSR = (uint32_t *)0xE000E204;
    *pIPSR = *pIPSR | (1<<(USART3_IRQ_NUM%32));

    //1.) Manually enable the ISER register of NVIC for USART3 using IRQ Number.
    uint32_t *pISER = (uint32_t *)0xE000E104;
    *pISER = *pISER | (1<<(USART3_IRQ_NUM%32));

    USART3_IRQHandler();

    return 0;
}

void USART3_IRQHandler(void)
{
	printf("Inside USART3IRQHandler Mode......!!!");
}

