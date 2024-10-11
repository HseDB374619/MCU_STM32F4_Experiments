#ifndef __GPIO_H__
#define __GPIO_H__

#include "main.h"

#define LED0_On			GPIO_WriteBit(LED0_GPIO_Port, LED0_Pin, Bit_RESET)
#define LED1_On			GPIO_WriteBit(LED1_GPIO_Port, LED1_Pin, Bit_RESET)
#define BEEP_On			GPIO_WriteBit(BEEP_GPIO_Port, BEEP_Pin, Bit_SET)

#define LED0_Off		GPIO_WriteBit(LED0_GPIO_Port, LED0_Pin, Bit_SET)
#define LED1_Off		GPIO_WriteBit(LED1_GPIO_Port, LED1_Pin, Bit_SET)
#define BEEP_Off		GPIO_WriteBit(BEEP_GPIO_Port, BEEP_Pin, Bit_RESET)

#define LED0_Set(x)		GPIO_WriteBit(LED0_GPIO_Port, LED0_Pin, x)
#define LED1_Set(x)		GPIO_WriteBit(LED1_GPIO_Port, LED1_Pin, x)

#define LED0_Toggle		GPIO_ToggleBits(LED0_GPIO_Port, LED0_Pin)
#define LED1_Toggle		GPIO_ToggleBits(LED1_GPIO_Port, LED1_Pin)

#define KEY0_Trigger	(GPIO_ReadInputDataBit(KEY0_GPIO_Port, KEY0_Pin) == Bit_RESET)
#define KEY1_Trigger	(GPIO_ReadInputDataBit(KEY1_GPIO_Port, KEY1_Pin) == Bit_RESET)
#define KEY2_Trigger	(GPIO_ReadInputDataBit(KEY2_GPIO_Port, KEY2_Pin) == Bit_RESET)
#define KEY3_Trigger	(GPIO_ReadInputDataBit(KEY3_GPIO_Port, KEY3_Pin) == Bit_SET)

void SP_GPIO_Init(void);

uint8_t Key_Read(void);

#endif /* __GPIO_H__ */
