#include "main.h"
#include "gpio.h"

#define workState		1

uint16_t workCnt = 0;

int main(void)
{
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
	SP_GPIO_Init();
	
	while (1)
	{
		#if (workState == 1)
		if (workCnt && ++workCnt > 200) workCnt = 0, BEEP_Off;
		if (workCnt == 0 && KEY0_Trigger) workCnt = 1, BEEP_On;
		
		#elif (workState == 2)
		if (++workCnt == 600) workCnt = 0;
		LED0_Set(workCnt / 100 % 2);
		LED1_Set(workCnt / 15 % 2);
		
		#elif (workState == 3)
		if (KEY0_Trigger) BEEP_On, LED1_Set(++workCnt / 25 % 2);
		else workCnt = 0, LED1_Off, BEEP_Off;
		
		#endif
		
		Delay_ms(10);
	}
}
