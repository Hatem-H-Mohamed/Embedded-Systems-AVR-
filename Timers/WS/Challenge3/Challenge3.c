/*
 * Challenge3.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Hateem Mohamed
 */



#include <avr/io.h>
#include <avr/interrupt.h>



void TIMER0_Init_PWM(unsigned char temp)
{
	TCNT0 = 0;

	TCCR0 |= (1<<WGM01) | (1<<WGM00)| (1<<CS01) | (1<<COM01);
	OCR0 = temp;

	DDRB |= (1<<3);

}



int main (void)
{


	TIMER0_Init_PWM(125);




	while(1)
	{



	}
}



