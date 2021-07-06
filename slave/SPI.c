

#define F_cpu 16000000UL
#include <avr/io.h>
#include "SPI.h"



void SPI_interrupt_enable(int Istate){
	switch(Istate){
		case Ienable :
		SPCR |= (1<<SPIE);
		break;
		case Idisable :
		SPCR &= ~(1<<SPIE);
		break;
		
	}
}


void SPI_enable(int state){
	switch(state){
		case enable :
		SPCR |= (1<<SPE);
		break;
		case disable :
		SPCR &= ~(1<<SPE);
		break;
		default:
		break;
	}
}


void SPI_data_order(int D_ORD){
	switch(D_ORD){
		case LSB :
		SPCR |= (1<<DORD);
		break;
		case MSB :
		SPCR &= ~(1<<DORD);
		break;
	}
	
}


void SPI_set(int mode){
	switch(mode){
		case master :
		SPCR |= (1<<MSTR);
		DDRB |= (1<<ss) | (1<<mosi) | (1<<sck);
		DDRB &= ~(1<<miso);
		break;
		case slave :
		SPCR &=~ (1<<MSTR); //SPCR |= (1<<MSTR); >>>>>  SPCR &= ~(1<<MSTR);
		DDRB &= ~(1<<mosi);
		DDRB &= ~(1<<ss);
		DDRB &= ~(1<<sck);
		DDRB |=  (1<<miso);
	
	}
}


void SPI_clock(int clock){
	      switch(clock)
	      {
		      
		      case fosc4:
			  SPCR &= ~((1<<SPR0) | (1<<SPR1)|(1<<SPI2X));//>>>>>>>
		      break;
			  case fosc16:
			  SPCR |=  (1<<SPR0);
			  SPCR &= ~((1<<SPR1) | (1<<SPI2X));//>>>>>>>
			  break;
			  case fosc64:
			  SPCR &= ~((1<<SPR0) | (1<<SPI2X));//>>>>>>>
		      SPCR |=  (1<<SPR1);
			  case fosc128:
			  SPCR |=  (1<<SPR0) | (1<<SPR1);
			  SPSR &=  ~(1<<SPI2X); // SPCR >>>>>>  SPSR
			  case fosc2:
			  SPCR &= ~((1<<SPR0) | (1<<SPR1));
			  SPCR |=  (1<<SPI2X);//>>>>>>>
			  case fosc8:
			  SPCR |=  (1<<SPR0) | (1<<SPI2X);//>>>>>>>
			  SPCR &=  ~(1<<SPR1);
			  case fosc32:
			  SPCR |=  (1<<SPR0) | (1<<SPR1) | (1<<SPI2X);//>>>>>>>
			  break;
		  }
}


void SPI_double_speed(int doublespeed){
	switch(doublespeed){
		case Dseneable :
		SPSR |= (1<<SPE);
		break;
		case DSdisable :
		SPSR &= ~(1<<SPE);
		break;
	}
}


void SPI_init(int mode){
	switch(mode){
		case master :
		SPCR |= (1<<MSTR);
		DDRB |= (1<<ss) | (1<<mosi) | (1<<sck);
		DDRB &= ~(1<<miso);
		break;
		case slave :
		SPCR &= ~(1<<MSTR);   //SPCR |=(1<<MSTR); >>>>>>  SPCR &= ~(1<<MSTR);
		DDRB &= ~(1<<mosi);
		DDRB &= ~(1<<ss);
		DDRB &= ~(1<<sck);
		DDRB |=  (1<<miso);
		
	}
}


char spI_read(){
		while(!(SPSR &(1 << SPIF)));
		return SPDR;
}

void spI_write(char data){
	   SPDR = data;
 	   while(!(SPSR &(1<<SPIF)));

}