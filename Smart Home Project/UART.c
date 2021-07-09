


#define F_CPU 16000000UL
#include <avr/io.h>
#include "uart.h"
#include <stdlib.h>

void uart_setBaudrate(unsigned int baudrate){
	unsigned int x =(F_CPU/(16.0 * baudrate))-1;  // calculate the number to set baudrate
	UBRRL = (char) x;    // to configure the First 8 bit
	UBRRH &= ~(1<<URSEL);   // Resit this bit yo allow to set higher bits of baudrate       
	UBRRH =(x>>8);     // configure the higher bits
}


void uart_send_char(char data){
	while(!(UCSRA & (1<<UDRE)));   //looping to check if UDR is Empty to Transmit New data
	UDR=data;   // store the data Transmitted in UDR
}

void init_uart(unsigned int baudrate){
	uart_setBaudrate(baudrate);  //call this function
	//UCSRC=0b10000110;    // the optionally if you need the synchronous 
	UCSRB |= (1<<TXEN)|(1<<RXEN);  // Enable the Transmitter & Receiver
    
}

void uart_send_str(char* data){
	for(int i=0 ; data[i]!='\0' ; i++){       // looping on the string to send character by character
		uart_send_char(data[i]);   // calling function to send the character
	}
}
void uart_send_num(int num){
	char buff[11];
	itoa(num , buff , 10);   // to convert the number to string  
	uart_send_str(buff);    // calling this function to send the number
}
void uart_newline(){
	uart_send_char('\r');  // call this function to go to New Line to write on it
}


//receive section

char uart_receive_char(){
	while (!(UCSRA & (1 << RXC)));    // looping to check if data is ready to receive the character 
	return (char)UDR;
}
void uart_receive_str(char* data){
	for(int i=0 ; data[i]!='\0' ; i++){     // looping to check if data is ready to receive the string 
		uart_receive_char(data[i]);
	}
}
void uart_receive_num(int num)
	{
	char buff[11];
	itoa(num , buff , 10);    // looping to check if data is ready to receive the number 
	uart_receive_str(buff);
	}
