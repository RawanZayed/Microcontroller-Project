/*
 * GccApplication6.c
 *
 * Created: 26/04/2023 03:14:21
 * Author : egypt
 */ 

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>
#define F_CPU 1000000

int main(void)
{ DDRC=0x00;/*PORTC is input*/
  DDRB=0b11100000;
  DDRA=0xFF;/*PORTA is output*/
  PORTC=0x00;/*PORTC is pull down*/	 
	
while(1){ //while(PINC!=0x00)
	if(PINC==0x01 && PORTA!=0b00000001){
		for(int i=0;i<5;i++){ //TURN LED OFF ANY OTHER LED
			PORTA&=~(1<<i);
		}
		 for(int j=5;j<=6;j++){ //TURN LED OFF
			 PORTB&=~(1<<j);
		 }
		PORTA|=0b00000001;
		PORTB|=(1<<PB5);
	}
 	else if(PINC==0x02 && PORTA!=0b00000010){//CHECK BUTTON PRESSED AND CHECK FLOOR LEVEL
 		for(int i=0;i<5;i++){ //TURN LED OFF
 			PORTA&=~(1<<i);
 		}
		 for(int j=5;j<=6;j++){ //TURN LED OFF
			 PORTB&=~(1<<j);
		 }
 		PORTA|=(1<<PA1);//TURN PA1 LED ON
		 PORTB|=(1<<PB6);
 	}
 	else if(PINC==0x04 && PORTA!=0b00000100){
 		for(int i=0;i<5;i++){ //TURN LED OFF
 			PORTA&=~(1<<i);
 		}
		 for(int j=5;j<=6;j++){ //TURN LED OFF
			 PORTB&=~(1<<j);
		 }
 		PORTA|=(1<<PA2);
		PORTB|=(1<<PB5); 
		PORTB|=(1<<PB6);
 	}
 	else if(PINC==0x08 && PORTA!=0b00001000){
 		for(int i=0;i<5;i++){ //TURN LED OFF
 			PORTA&=~(1<<i);
 		}
		 for(int j=5;j<=6;j++){ //TURN LED OFF
			  PORTB&=~(1<<j);
		  }
 		PORTA|=(1<<PA3);
		PORTB|=(1<<PB5);
 	}
 	else if(PINC==0x10 && PORTA!=0b00010000){
 		for(int i=0;i<5;i++){ //TURN LED OFF
 			PORTA&=~(1<<i);
 		}
		 for(int j=5;j<=6;j++){ //TURN LED OFF
			 PORTB&=~(1<<j);
		 }
 		PORTA|=(1<<PA4);
		PORTB|=(1<<PB6); 
 	}
 	else if(PINC==0x20 && PORTA!=0b00100000){
 		for(int i=0;i<5;i++){ //TURN LED OFF
 			PORTA&=~(1<<i);
 		}
		  for(int j=5;j<=6;j++){ //TURN LED OFF
			  PORTB&=~(1<<j);
		  }
 		PORTA|=(1<<PA5);
		PORTB|=(1<<PB5); 
		PORTB|=(1<<PB6);
 	}
// 	else if(PINC==0x06 && PORTA==0b00000001) {//FLOOR 1 AND FLOOR2,3 IS REQUESTED OUT
// 		for(int i=0;i<5;i++){ //TURN LED OFF
// 			PORTA&=~(1<<i);
// 		}
// 		PORTA|=(1<<PA1);
// 		_delay_ms(5000);
// 		PORTA&=~(1<<PA1);
// 		PORTA|=(1<<PA2);
// 		
// 	}
}
}
	

