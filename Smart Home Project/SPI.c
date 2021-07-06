

#define F_cpu 16000000UL
#include <avr/io.h>
#include "SPI.h"



void SPI_interrupt_enable(int Istate){
	switch(Istate){        // Indicate the state of interrupt 
		case Ienable :
		SPCR |= (1<<SPIE);
		break;
		case Idisable :
		SPCR &= ~(1<<SPIE);
		break;
		
	}
}


void SPI_enable(int state){
	switch(state){     // Indicate the SPI can be enable or not
		case enable :
		SPCR |= (1<<SPE);  // set this bit to enable the SPI
		break;
		case disable :
		SPCR &= ~(1<<SPE);  // clear this bit to disable the SPI
		break;
	}
	
	
	
}


void SPI_data_order(int D_ORD){
	switch(D_ORD){                 // to indicate which bit you want to transmit firstly
		case LSB :                 // to get last bit transmitted firstly
		SPCR |= (1<<DORD);         // set this bit to get last bit transmitted firstly
		break;
		case MSB :             // to get most bit transmitted firstly
		SPCR &= ~(1<<DORD);    // set this bit to get most bit transmitted firstly
		break;
	}
	
}


void SPI_set(int mode){          // to select the mode (Master or slave)
	switch(mode){
		case master :
		SPCR |= (1<<MSTR);
		DDRB |= (1<<ss) | (1<<mosi) | (1<<sck);
		DDRB &= ~(1<<miso);
		break;
		case slave :
		SPCR &= ~(1<<MSTR); 
		DDRB &= ~(1<<mosi);
		DDRB &= ~(1<<ss);
		DDRB &= ~(1<<sck);
		DDRB |=  (1<<miso);
	
	}
}


void SPI_clock(int clock){                      // to select the frequency
	      switch(clock)
	      {
		      
		      case fosc4:
			  SPCR &= ~((1<<SPR0) | (1<<SPR1)|(1<<SPI2X));
		      break;
			  case fosc16:
			  SPCR |=  (1<<SPR0);
			  SPCR &= ~((1<<SPR1) | (1<<SPI2X));
			  break;
			  case fosc64:
			  SPCR &= ~((1<<SPR0) | (1<<SPI2X));
		      SPCR |=  (1<<SPR1);
			  case fosc128:
			  SPCR |=  (1<<SPR0) | (1<<SPR1);
			  SPSR &=  ~(1<<SPI2X);
			  case fosc2:
			  SPCR &= ~((1<<SPR0) | (1<<SPR1));
			  SPCR |=  (1<<SPI2X);
			  case fosc8:
			  SPCR |=  (1<<SPR0) | (1<<SPI2X);
			  SPCR &=  ~(1<<SPR1);
			  case fosc32:
			  SPCR |=  (1<<SPR0) | (1<<SPR1) | (1<<SPI2X);
			  break;
		  }
}


void SPI_double_speed(int doublespeed){        // it is optionally and we do this function on the clock
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
		SPCR &= ~(1<<MSTR);
		DDRB &= ~(1<<mosi);
		DDRB &= ~(1<<ss);
		DDRB &= ~(1<<sck);
		DDRB |=  (1<<miso);
		
	}
}


char spI_read(){                      // call this function to receive data
		while(!(SPSR &(1<<SPIF)));
		return SPDR;
}

void spI_write(char data){           // call this function to transmit data
	   SPDR = data;
 	   while(!(SPSR &(1<<SPIF)));    // looping to check if data register can transmit data

}