#include "sys.h"
#include "delay.h"
#include "usart.h"
#include "led.h"

/*
实现逻辑：LED0的闪烁周期为2s,LED1的闪烁周期为0.7s，则二者每翻转一次电平的时间分别为1000ms和350ms，二者的最大
公约数为50，则可设置一计数器counter，每50ms计数加1，当计数为7的整数倍时，翻转LED1的电平；当计数为20的整数倍
时，翻转LED0的电平。当counter计数到二者的公倍数且两个LED各自完成了完整的亮灭过程时（如：亮-灭-亮-灭），
将counter清零。
*/

int main(void)
{
	delay_init(168);
	LED_Init();         // 初始化LED
	uint16_t counter=0;//声明计数器变量
	while(1)
	{
		delay_ms(50);
		counter++;
		if(counter%7==0)
		{
			GPIO_ToggleBits(GPIOF,GPIO_Pin_10);
		}
		if(counter%20==0)
		{
			GPIO_ToggleBits(GPIOF,GPIO_Pin_9);
		}
		
		if(counter==280)
		{
			counter=0;
		}
	}
}