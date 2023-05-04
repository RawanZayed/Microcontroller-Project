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



int main(void){
	
	DDRC=0x00;/*PORTC is input*/
	DDRB=0b11100000;//PORTB is Output
	DDRA=0xFF;/*PORTA is output*/
	PORTC=0x00;/*PORTC is pull down*/
	int j=0;//
	int k=3;
	unsigned long array[k];
	while(1){
		for( k=0; k<3;k++){
			array[k]=(PIND<<k);
		}
		
		if(PINC==0x01 && j!=1){//FLOOR 1
			
			for(int j=5;j<=6;j++){ //TURN LED OFF
				PORTB&=~(1<<j);
			}
			for(int i=0;i<5;i++){ //TURN OFF LED
				PORTA&=~(1<<i);
			}
			PORTA=0b00000001;
			PORTB=(1<<PB5);
			j=1;
			
		}
		else if(PINC==0x02 && j!=2){//CHECK BUTTON PRESSED AND CHECK FLOOR LEVEL
			
			for(int j=5;j<=6;j++){ //TURN LED OFF
				PORTB&=~(1<<j);
			}
			for(int i=0;i<5;i++){ //TURN OFF LED
				PORTA&=~(1<<i);
			}
			PORTA=0b00010000;//TURN PA1 LED ON
			PORTB=(1<<PB6);
			j=2;
		}
		else if(PINC==0x04 && j!=3){
			
			for(int j=5;j<=6;j++){ //TURN LED OFF
				PORTB&=~(1<<j);
			}
			for(int i=0;i<5;i++){ //TURN OFF LED
				PORTA&=~(1<<i);
			}
			PORTA=0b00000000;
			PORTB=(1<<PB5);
			PORTB=(1<<PB6);
			j=3;
		}
	}

