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
		// === 第 1 下：“登” (50ms) ===
        GPIOD->BSRR = (1 << 4);  // ON
        Delay_ms(50);
        
        // === 间隔 (50ms) ===
        GPIOD->BRR  = (1 << 4);  // OFF
        Delay_ms(50);
        
        // === 第 2 下：“登” (50ms) ===
        GPIOD->BSRR = (1 << 4);  // ON
        Delay_ms(50);
        
        // === 静默继续 (0.8秒) ===
        GPIOD->BRR  = (1 << 4);  // OFF
        Delay_ms(800);
	}
}
