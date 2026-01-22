#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	// Initialize
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin  = GPIO_Pin_1;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStruct);
	// Light up
	while (1)
	{
		GPIO_WriteBit(GPIOB, GPIO_Pin_1, (BitAction) 0);
		Delay_ms(500);
		GPIO_WriteBit(GPIOB, GPIO_Pin_1, Bit_SET);
		Delay_ms(500);
	}
}
