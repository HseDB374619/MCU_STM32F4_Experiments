#include "stm32f4xx.h"
#include "usart.h"
#include "delay.h"

#define LED1_ON  GPIO_ResetBits(GPIOF,GPIO_Pin_10) //����
#define LED1_OFF GPIO_SetBits(GPIOF,GPIO_Pin_10) //���
#define BEEP_ON  GPIO_SetBits(GPIOF,GPIO_Pin_8) //��������
#define BEEP_OFF GPIO_ResetBits(GPIOF,GPIO_Pin_8) //����������

void key_init(void);
void led_init(void);
void beep_init(void);
void led_blink(void);

int main(void)
{
	delay_init(168);
	key_init();
	led_init();
	beep_init();
	while(1)
	{
		if(!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4))
		{
			delay_ms(20);
			if(!GPIO_ReadInputDataBit(GPIOE,GPIO_Pin_4))
			{
				BEEP_ON;
				led_blink();
			}
			else 
			{
				BEEP_OFF;
				LED1_OFF;
			}
			
		}
		else
		{
				BEEP_OFF;
				LED1_OFF;
		}
	}
}

void key_init(void) //������ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_4;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_IN;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_PuPd=GPIO_PuPd_UP;
	GPIO_Init(GPIOE,&GPIO_InitStructure);
}

void beep_init(void) //��������ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_8;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	BEEP_OFF;
}

void led_init(void) //LED��ʼ��
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOF,ENABLE);
	GPIO_InitStructure.GPIO_Pin=GPIO_Pin_10;
	GPIO_InitStructure.GPIO_Mode=GPIO_Mode_OUT;
	GPIO_InitStructure.GPIO_Speed=GPIO_Speed_100MHz;
	GPIO_InitStructure.GPIO_OType=GPIO_OType_PP;
	GPIO_Init(GPIOF,&GPIO_InitStructure);
	LED1_OFF;
}
void led_blink(void)
{   
	LED1_ON;
	delay_ms(5);
	LED1_OFF;
	delay_ms(500);
}