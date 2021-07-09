 /*
 * Smart Home Project.c
 *
 * Created: 27/03/2021 05:52:46 م
 * Author : win 7
 */ 




#define F_cpu 16000000UL
#include "SPI.h"
#include "uart.h"
#include <avr/io.h>




int main(void)
{
	/* Replace with your application code */
	char x ;
	init_uart(9600);
	SPI_init(master);
	SPI_clock(fosc128);
	SPI_enable(enable);
	DDRC = 0xFF;
	DDRA = 0xFF;
	while (1)
	{
		x = uart_receive_char();
		PORTC = x;
		uart_send_char(x);
		if (x == 'B')
		{
			PORTA = 1;
		}
		spI_write(x);
	}
}