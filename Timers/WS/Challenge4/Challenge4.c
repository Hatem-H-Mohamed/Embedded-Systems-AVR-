/*
 * Challenge4.c
 *
 *  Created on: Jul 7, 2024
 *      Author: Hateem Mohamed
 */



#include <avr/io.h>
#include <avr/interrupt.h>

unsigned char flag = 0;


ISR(TIMER1_COMPA_vect)
{

	if (flag == 0)
	{
		PORTC ^= (1<<0);
		OCR1A = 375;
		flag = 1;
	}
	else
	{
		PORTC ^= (1<<0);
		OCR1A = 125;
		flag = 0;
	}


}



void TIMER1_Init(void)
{
	TCNT1 = 0;

	OCR1A = 125;

	TIMSK |= (1<<OCIE1A);

	TCCR1B |= (1<<WGM12) | (1<<CS11);

	SREG |= (1<<7);

}



int main (void)
{

	DDRC |= (1<<0);
	PORTC |= (1<<0);

	TIMER1_Init();


	while(1)
	{

	}
}
