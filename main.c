/*
 * GccApplication7.c
 *
 * Created: 26/04/2023 20:28:57
 * Author : egypt
 */ 

#include <avr/io.h>
#include <avr/sfr_defs.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include <string.h>

#define CPU 1000000


//////////////// variable declarations////////////////////////////

unsigned int angle=0,new_angle,set_angle=0,num_of_pulses, rotate_reverse_flag=0,uiAddress;
//////////////// function to increase angle by 15 //////////////////
void inc_angle()
{
	if(angle<345) angle+=15; // increase angle till 345 degree
	
	new_angle = angle;  // update new angle value
}

////////////// function to decrease angle by 15 ////////////////
void dec_angle()
{
	if(angle>0) angle-=15;  // decrease angle till 0 degree
	
	new_angle = angle;  // update new angle value
}

///////////////// function to rotate motor till desire angle //////////
void rotate_motor()
{
	int i;
	if(new_angle>set_angle)  // if new entered angle is larger
	{
		num_of_pulses = (new_angle-set_angle) / 15; // set number of
		rotate_reverse_flag=0; // pulses and clear flag to rotate
		// motor CCW
	}
	else     // if new entered angle is smaller
	{
		num_of_pulses = (set_angle-new_angle) / 30; // set number
		rotate_reverse_flag=1; // of pulses and set flag to rotate
		// motor CW
	}
	if(rotate_reverse_flag==0) // check if flag is clear
	{
		for(i=0;i<num_of_pulses;i++) // generate pulse sequence to
		{     // rotate motor CCW
			PORTB = 0x01;
			_delay_ms(100);
			PORTB = 0x02;
			_delay_ms(100);
			PORTB = 0x04;
			_delay_ms(100);
			PORTB = 0x08;
			_delay_ms(100);
		}
	}
	else      // else if flag is set
	{
		for(i=0;i<num_of_pulses;i++) // generate pulse sequence to
		{
			PORTB = 0x08;  // rotate motor CW
			_delay_ms(100);
			PORTB = 0x04;
			_delay_ms(100);
			PORTB = 0x02;
			_delay_ms(100);
			PORTB = 0x01;
			_delay_ms(100);
		}
	}
	set_angle = new_angle;  // save angle value

}

/////////////////// main function starts here /////////////////////////
int main(void)
{
	DDRA=0xFF;    // PORTB, PORTC and PORTD as
	DDRC=0x00;    // PORT A as an input port
	
	
	loop:while(PINC==0xF0);  // loop until no button is pressed
	switch(PINC)   // when button is pressed
	{
		case 0x01:   // if 1st button is pressed
		inc_angle(); // increment angle by 15 degree
		_delay_ms(200); // key debounce delay
		break;  // get out of loop
		
		case 0xF2:   // same as above
		dec_angle();
		_delay_ms(200);
		break;
		
		case 0xF4:   // for 3rd key
		rotate_motor(); // rotate motor
		break;
	}
	goto loop;    // continuous loop
 
 unsigned char EEPROM_read(unsigned uiAddress)
 {
	 /* Wait for completion of previous write */
	 while(EECR & (1<<EEWE))
	 ;
	 /* Set up address register */
	 EEAR = uiAddress;
	 /* Start eeprom read by writing EERE */
	 EECR |= (1<<EERE);
	 /* Return data from data register */
	 return EEDR;
 }





}

