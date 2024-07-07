/*
 * Challenge1.c
 *
 *  Created on: Jul 6, 2024
 *      Author: Hateem Mohamed
 */

#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char cnt_7 = 0, cnt_I = 0;


ISR(TIMER0_OVF_vect)
{
	if (cnt_I == 126) cnt_I = 0;
	cnt_I++;
	if (cnt_I == 125)
	{
		if (cnt_7 == 10) cnt_7 = 0;
		PORTC &= 0xF0;
		PORTC |= cnt_7;
		cnt_7++;
	}

}


void TIMER0_Init (void)
{
	TCNT0 = 0; //set initial value 0

	//normal mode timer (default)

	//congif the prescaler  /1024 and set FOC
	TCCR0 |= (1<<CS02) | (1<<FOC0);

	//enable overflow interrupt enable
	TIMSK |= (1<<TOIE0);

	//enable i bit
	SREG |= (1<<7);
}


int main (void)
{

	DDRC |=0x0F;
	PORTC &=0xF0;

	TIMER0_Init();

	while (1)
	{

	}
}
