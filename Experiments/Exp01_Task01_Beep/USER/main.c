#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"
void key_init(void) //按键初始化函数
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP; //因为key_0连接GND，故将其设置为上拉输入
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}
void beep_init(void) //蜂鸣器初始化函数
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;//推挽输出
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	GPIO_ResetBits(GPIOF,GPIO_Pin_8);//初始化设置为低电平
}

int main(void)
{
	delay_init(168);
	key_init();
	beep_init();
	while(1)
	{
		if(!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4))//进行首次按键检测，如检测到低电平，则去抖
		{
			delay_ms(20);//延迟20ms，去抖
			if(!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4))
			{
			GPIO_SetBits(GPIOF,GPIO_Pin_8);
			delay_ms(2000);
			GPIO_ResetBits(GPIOF,GPIO_Pin_8);
			}
		}
	}
}
