#include "stm32f10x.h"                  // Device header
#include "Delay.h"

int main(void)
{
	// Initialize
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOD, ENABLE);
	GPIO_InitTypeDef GPIO_InitStruct;
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOD, &GPIO_InitStruct);
	
	while (1)
	{
		GPIOD->ODR = GPIOD->ODR ^ GPIO_Pin_4;
		Delay_ms(500);  // 看似控制的是时间，实则控制的是改变的频率（其中一个状态保持的）。
	}
}
