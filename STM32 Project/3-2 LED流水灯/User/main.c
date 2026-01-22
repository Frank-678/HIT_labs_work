#include "stm32f10x.h"                  // Device header
#include "Delay.h"

#define STAY_TIME 500

int main(void)
{
	// Initialize
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB | RCC_APB2Periph_GPIOF, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructB;
	GPIO_InitStructB.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_5;
	GPIO_InitStructB.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructB.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructB);
	GPIO_InitTypeDef GPIO_InitStructF;
	GPIO_InitStructF.GPIO_Pin = GPIO_Pin_11 | GPIO_Pin_12;
	GPIO_InitStructF.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructF.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Init(GPIOF, &GPIO_InitStructF);
	// Light up
	while (1)
	{
		GPIO_Write(GPIOF, 0xFFFF);
		
		GPIO_Write(GPIOB, ~0x0001);
		Delay_ms(STAY_TIME);
		GPIO_Write(GPIOB, ~0x0002);
		Delay_ms(STAY_TIME);
		GPIO_Write(GPIOB, ~0x0020);
		Delay_ms(STAY_TIME);
		
		GPIO_Write(GPIOB, 0xFFFF);		
		
		GPIO_Write(GPIOF, ~0x0800);
		Delay_ms(STAY_TIME);
		GPIO_Write(GPIOF, ~0x1000);
		Delay_ms(STAY_TIME);
	}
}
