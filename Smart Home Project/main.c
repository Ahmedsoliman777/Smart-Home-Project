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
	
    while (1) 
    {
		x = uart_receive_char();
		spI_write(x);
    }
}

