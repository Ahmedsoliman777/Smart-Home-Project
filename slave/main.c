

#define LED0  2
#define LED1  7

#define F_cpu 16000000UL
#include "SPI.h"
#include <avr/io.h>


int main(void)
{
    /* Replace with your application code */
	char x;
	SPI_init(slave);
	SPI_clock(fosc128);
	DDRC |= (1<<LED0) | (1<<LED1);
	SPI_enable(enable);
	
	
    while (1) 
    {
		x = spI_read();
		if (x=='A')
		{
			PORTC |= (1<<LED0);
		}
		else if (x=='B')
		{
			PORTC &= ~(1<<LED0);
		}
		else if (x=='C')
		{
			PORTC |= (1<<LED1);
		}
		else if (x=='D')
		{
			PORTC &= ~(1<<LED1);
		}
		else
		{
		}
    }
}

