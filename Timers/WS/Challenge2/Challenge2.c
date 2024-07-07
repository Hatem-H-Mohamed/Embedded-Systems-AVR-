/*
 * Challenge2.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Hateem Mohamed
 */

#include <avr/io.h>
#include <avr/interrupt.h>


unsigned char cnt = 0;


ISR(TIMER0_COMP_vect)
{
	cnt++;

	PORTC ^= (1<<0);
	if (cnt == 2)PORTC ^= (1<<1);
	else if (cnt == 4)
	{
		PORTC ^= (1<<1);
		PORTC ^= (1<<2);
		cnt = 0;
	}
}



void TIMER0_Init(void)
{
	TCNT0 = 0;

	OCR0 = 50;

	TIMSK |= (1<<OCIE0);


	TCCR0 |= (1<<FOC0) | (1<<WGM01)|(1<<CS01);

	SREG |= (1<<7);
}



int main (void)
{

	DDRC |= 0b00000111;
	PORTC &= 0b11111000;

	TIMER0_Init();


	while(1)
	{

	}
}
