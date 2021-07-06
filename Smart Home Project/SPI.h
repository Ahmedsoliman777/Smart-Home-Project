


#include <stdlib.h>

#ifndef SPI_H_
#define SPI_H_


// select config

#define enable            0
#define disable           1  
#define Ienable           2
#define Idisable          3
#define LSB               4
#define MSB               5
#define master            6
#define slave             7


#define ss                4
#define sck               7  
#define miso              6
#define mosi              5

//SELECT SCK
#define  fosc4            1
#define  fosc16           2 
#define  fosc64           3
#define  fosc128          4 
#define  fosc2            5 
#define  fosc8            6
#define  fosc32           7
#define  Dseneable        8
#define  DSdisable        9



void SPI_interrupt_enable(int Istate);
void SPI_enable(int state);
void SPI_data_order(int D_ORD);
void SPI_set(int mode);
void SPI_clock(int clock);
void SPI_double_speed(int doublespeed);
void SPI_init(int mode);
char spI_read();
void spI_write(char data);



#endif /* SPI_H_ */