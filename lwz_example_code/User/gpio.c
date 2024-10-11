#include "gpio.h"

void SP_GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOG, ENABLE);
	
	GPIO_InitStruct.GPIO_Pin = KEY3_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_DOWN;
	GPIO_Init(GPIOA, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = KEY2_Pin | KEY1_Pin | KEY0_Pin;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_Init(GPIOE, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = BEEP_Pin | LED0_Pin | LED1_Pin;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Low_Speed;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOF, &GPIO_InitStruct);
	
	GPIO_InitStruct.GPIO_Pin = LCD_BL_Pin;
	GPIO_Init(LCD_BL_GPIO_Port, &GPIO_InitStruct);
	
	GPIO_WriteBit(BEEP_GPIO_Port, BEEP_Pin, Bit_RESET);
	GPIO_WriteBit(LED0_GPIO_Port, LED0_Pin, Bit_SET);
	GPIO_WriteBit(LED1_GPIO_Port, LED1_Pin, Bit_SET);
	GPIO_WriteBit(LCD_BL_GPIO_Port, LCD_BL_Pin, Bit_RESET);
}

uint8_t Key_Read(void)
{
	static uint16_t cnt = 0;
	static uint8_t num = 0xFF;
	if (KEY0_Trigger) cnt++, num = 0;
	else if (KEY1_Trigger) cnt++, num = 1;
	else if (KEY2_Trigger) cnt++, num = 2;
	else if (KEY3_Trigger) cnt++, num = 3;
	else if (cnt < 10) cnt = 0, num = 0xFF;
	else { cnt = 0; return num; }
	return 0xFF;
}
