#include "sys.h"

void Delay_us(uint32_t xus)
{
	SysTick->LOAD = 168 * xus;
	SysTick->VAL = 0x000000;
	SysTick->CTRL = 0x00000005;
	while(!(SysTick->CTRL & 0x00010000));
	SysTick->CTRL = 0x00000004;
}

void Delay_ms(uint32_t xms)
{
	while (xms--) Delay_us(1000);
}
