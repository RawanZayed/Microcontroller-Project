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
		for(int i=0;i<5;i++){ //TURN OFF ALL LEDS
			PORTA&=~(1<<i);
		}
		 for(int j=5;j<=6;j++){ //TURN OFF LED 
			 PORTB&=~(1<<j);
		 }
		PORTA|=0b00000001;
		PORTB|=(1<<PB5);
	}
 	else if(PINC==0x02 && PORTA!=0b00000010){//CHECK BUTTON PRESSED AND CHECK FLOOR LEVEL
 		for(int i=0;i<5;i++){ //TURN OFF LED 
 			PORTA&=~(1<<i);
 		}
		 for(int j=5;j<=6;j++){ //TURN OFF LED 
			 PORTB&=~(1<<j);
		 }
 		PORTA|=(1<<PA1);//TURN PA1 LED ON
		 PORTB|=(1<<PB6);
 	}
 	else if(PINC==0x04 && PORTA!=0b00000100){
 		for(int i=0;i<5;i++){ //TURN OFF LED 
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
 		for(int i=0;i<5;i++){ //TURN OFF LED 
 			PORTA&=~(1<<i);
 		}
		 for(int j=5;j<=6;j++){ //TURN OFF LED 
			  PORTB&=~(1<<j);
		  }
 		PORTA|=(1<<PA3);
		PORTB|=(1<<PB5);
 	}
 	else if(PINC==0x10 && PORTA!=0b00010000){
 		for(int i=0;i<5;i++){ //TURN OFF LED 
 			PORTA&=~(1<<i);
 		}
		 for(int j=5;j<=6;j++){ //TURN OFF LED 
			 PORTB&=~(1<<j);
		 }
 		PORTA|=(1<<PA4);
		PORTB|=(1<<PB6); 
 	}
 	else if(PINC==0x20 && PORTA!=0b00100000){
 		for(int i=0;i<5;i++){ //TURN OFF LED 
 			PORTA&=~(1<<i);
 		}
		  for(int j=5;j<=6;j++){ //TURN OFF LED 
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


//////////// variable declarations////////////////////////////

//unsigned int angle=0,new_angle,set_angle=0,num_of_pulses, rotate_reverse_flag=0,uiAddress;
////////////// function to increase angle by 15 //////////////////
// void inc_angle()
// {
// 	if(angle<345) angle+=15; // increase angle till 345 degree
//
// 	new_angle = angle;  // update new angle value
// }

////////// function to decrease angle by 15 ////////////////
// void dec_angle()
// {
// 	if(angle>0) angle-=15;  // decrease angle till 0 degree
//
// 	new_angle = angle;  // update new angle value
// }

/////////// function to rotate motor till desire angle //////////
// 			void rotate_motor()
// 			{
// 				int i;
// 				if(new_angle>set_angle)  // if new entered angle is larger
// 				{
// 					num_of_pulses = (new_angle-set_angle) / 15; // set number of
// 					rotate_reverse_flag=0; // pulses and clear flag to rotate
// 					// motor CCW
// 				}
// 				else     // if new entered angle is smaller
// 				{
// 					num_of_pulses = (set_angle-new_angle) / 30; // set number
// 					rotate_reverse_flag=1; // of pulses and set flag to rotate
// 					// motor CW
// 				}
// 				if(rotate_reverse_flag==0) // check if flag is clear
// 				{
// 					for(i=0;i<num_of_pulses;i++) // generate pulse sequence to
// 					{     // rotate motor CCW
// 						PORTB = 0x01;
// 						_delay_ms(100);
// 						PORTB = 0x02;
// 						_delay_ms(100);
// 						PORTB = 0x04;
// 						_delay_ms(100);
// 						PORTB = 0x08;
// 						_delay_ms(100);
// 		}
// 	}
// 	else      // else if flag is set
// 	{
// 		for(i=0;i<num_of_pulses;i++) // generate pulse sequence to
// 		{
// 			PORTB = 0x08;  // rotate motor CW
// 			_delay_ms(100);
// 			PORTB = 0x04;
// 			_delay_ms(100);
// 			PORTB = 0x02;
// 			_delay_ms(100);
// 			PORTB = 0x01;
// 			_delay_ms(100);
// 		}
// 	}
// 	set_angle = new_angle;  // save angle value
//
// }
//
// ///////////////// main function starts here /////////////////////////
// int main(void)
// {
// 	DDRA=0xFF;    // PORTB, PORTC and PORTD as
// 	DDRC=0x00;    // PORT A as an input port
//
//
// 	loop:while(PINC==0xF0);  // loop until no button is pressed
// 	switch(PINC)   // when button is pressed
// 	{
// 		case 0x01:   // if 1st button is pressed
// 		//inc_angle(); // increment angle by 15 degree
// 		//_delay_ms(200); // key debounce delay
// 		break;  // get out of loop
//
// 		case 0xF2:   // same as above
// 		//dec_angle();
// 		//_delay_ms(200);
// 		break;
// //
// // 		case 0xF4:   // for 3rd key
// 		//rotate_motor(); // rotate motor
// 		break;
// 	}
// 	goto loop;    // continuous loop
//





//
// }
// 		
// 	}
}
}
	

