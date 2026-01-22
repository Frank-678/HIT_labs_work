#include "stm32f10x.h"                  // Device header

int main(void)
{
	// 寄存器版本[查表STM32F10xxx参考手册]; set to "on" (default is off)
	// RCC->APB2ENR = 0x00000008;
	// GPIOB->CRL = 0x00000003;
	// GPIOB->ODR &= ~1;
	
	// 库函数版本
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0;
    GPIO_Init(GPIOB, &GPIO_InitStructure);
	
	GPIO_ResetBits(GPIOB, GPIO_Pin_0); // 其实本来默认是0，上面只启动了PB0，默认只有PB0亮，这里显式ResetBits设为低电平
	while (1)
	{
		
	}
}
