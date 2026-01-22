#include "stm32f10x.h"                  // Device header

#define BEEP_PORT      GPIOD
#define BEEP_PIN       GPIO_Pin_4
#define BEEP_RCC       RCC_APB2Periph_GPIOD

int main(void)
{
	// Initialize
	RCC_APB2PeriphClockCmd(BEEP_RCC, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = BEEP_PIN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(BEEP_PORT, &GPIO_InitStruct);
	
	// BEEP
	GPIO_WriteBit(BEEP_PORT, BEEP_PIN, Bit_SET);
	
	while (1)
	{

	}
}
