   
      
#include <stdlib.h>


#ifndef UART_H_
#define UART_H_

// send functions

void init_uart();
void uart_setBaudrate(unsigned int);
void uart_send_char(char);
void uart_send_str(char*);
void uart_send_num(int );
void uart_newline();


// Receive functions


char uart_receive_char();
void uart_receive_str(char* );
void uart_receive_num(int );





#endif /* UART_H_ */