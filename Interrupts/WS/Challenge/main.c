/*
 * main.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Hateem Mohamed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


unsigned char cnt = 0;



ISR(INT2_vect)
{
	cnt++;
	if(cnt == 10)cnt = 0;
	PORTC &= 0xF0;
	PORTC |= cnt;
}


void INT2_Init (void)
{
	MCUCSR |= (1<<6);
	GICR |= (1<<5);
	SREG |= (1<<7);
}


int main (void)
{
	DDRC |= 0x0F;
	PORTC &= 0xF0;

	INT2_Init();

	while(1)
	{

	}
}

