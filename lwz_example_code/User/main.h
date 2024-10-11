#ifndef __MAIN_H__
#define __MAIN_H__

#include "stm32f4xx.h"                  // Device header
#include "sys.h"

#include "stdio.h"
#include "string.h"
#include "stdarg.h"
#include "stdbool.h"

#define KEY2_Pin			GPIO_Pin_2
#define KEY2_GPIO_Port		GPIOE
#define KEY1_Pin			GPIO_Pin_3
#define KEY1_GPIO_Port		GPIOE
#define KEY0_Pin			GPIO_Pin_4
#define KEY0_GPIO_Port		GPIOE
#define BEEP_Pin			GPIO_Pin_8
#define BEEP_GPIO_Port		GPIOF
#define LED0_Pin			GPIO_Pin_9
#define LED0_GPIO_Port		GPIOF
#define LED1_Pin			GPIO_Pin_10
#define LED1_GPIO_Port		GPIOF
#define KEY3_Pin			GPIO_Pin_0
#define KEY3_GPIO_Port		GPIOA
#define LCD_BL_Pin			GPIO_Pin_15
#define LCD_BL_GPIO_Port	GPIOB

#endif /* __MAIN_H__ */
