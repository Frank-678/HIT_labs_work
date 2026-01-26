#include "stm32f10x.h"                  // Device header

void Key_init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOF, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructureF;
	GPIO_InitStructureF.GPIO_Mode  = GPIO_Mode_IPD;
	GPIO_InitStructureF.GPIO_Pin   = GPIO_Pin_1;
	GPIO_InitStructureF.GPIO_Speed = (GPIOSpeed_TypeDef) 3;  //输入模式没有用
	GPIO_Init(GPIOF, &GPIO_InitStructureF);
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
	GPIO_InitTypeDef GPIO_InitStructureA;
	GPIO_InitStructureA.GPIO_Mode  = GPIO_Mode_IPD;
	GPIO_InitStructureA.GPIO_Pin   = GPIO_Pin_0;
	GPIO_InitStructureA.GPIO_Speed = (GPIOSpeed_TypeDef) 3;  //输入模式没有用
	GPIO_Init(GPIOA, &GPIO_InitStructureA);
}

uint8_t Key_GetNum(void)
{
	uint8_t KeyNum = 0;
	
	if (GPIO_ReadInputDataBit(GPIOF,GPIO_Pin_1) == 1)
}
