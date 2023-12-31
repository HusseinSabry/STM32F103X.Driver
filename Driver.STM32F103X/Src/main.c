/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */
#include "stdint.h"
#include "stdio.h"
#include "stdlib.h"

#include <Stm32_f103_c6_GPIO_Driver.h>
#include "Stm32_f103_c6.h"
#include "keybad.h"
#include "lcd.h"
#include "Stm32_f103_c6_EXTI_Driver.h"
#include "Stm32_f103_c6_USART_Driver.h"






void wait_ms(uint32_t time)
{
	uint32_t i,j;
	for(i=0;i<time;i++)
	{

		for(j=0;j<255;j++);
	}


}

void Clk_Init()
{
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
	RCC_AFIO_CLK_EN();

}




unsigned char ch;

void Hussein_IRQ_Callback(void)
{
	MCAL_UART_ReceiveData(USART1, (uint16_t*) &ch, disable);
	MCAL_UART_SendData(USART1,(uint16_t*) &ch, enable);



}
int main(void)
{
	USART_Coinf uartCFG;
	Clk_Init();


	uartCFG.BaudRate = USART_BaudRate_115200;
	uartCFG.HWFlowCTL = USART_HWFLOWCTL_NONE;
	uartCFG.IRQ_ENABLE = USART_IRQ_ENABLE_RXNEIE;
	uartCFG.P_IRQ_CALLBACK = Hussein_IRQ_Callback;
	uartCFG.Parity = USART_Parity_NONE;
	uartCFG.PayLoadLenght = USART_PayLoad_Length_8B;
	uartCFG.StopBits = USART_STOP_ONE;
	uartCFG.USART_Mode =USART_Mode_TX_RX;
	MCAL_UART_Init(USART1,&uartCFG);
	MCAL_UART_GPIO_Set_Pins(USART1);




	while (1)
	{

	}




}









