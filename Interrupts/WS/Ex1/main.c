/*
 * main.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Hateem Mohamed
 */

#include <avr/io.h>
#include <avr/interrupt.h>



ISR(INT0_vect)
{
	PORTC ^= (1<<0);
}


void INT0_Init (void)
{
	MCUCR |= (1<<0) | (1<<1); // set bit 1 and 2 to config as rising edge
	GICR |= (1<<6); //set bit 6 in GICR to enable INTO
	SREG |= (1<<7); //set i bit in SREG to enable global interrupts
}

void LED_Init (void)
{
	DDRC |= (1<<0);
	PORTC |= (1<<0);
}

int main (void)
{
	LED_Init();
	INT0_Init();


	while(1)
	{

	}
}

