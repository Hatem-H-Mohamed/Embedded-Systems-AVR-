/*
 * main.c
 *
 *  Created on: Jul 5, 2024
 *      Author: Hateem Mohamed
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/delay.h>


unsigned char g_i_flag = 0;


ISR(INT1_vect)
{
	g_i_flag = 1;
}


void INT1_Init (void)
{
	MCUCR |= (1<< 2) | (1<<3); // set bit 2 and 3 to config as rising edge
	GICR |= (1<<7); //set bit 7 in GICR to enable INT1
	SREG |= (1<<7); //set i bit in SREG to enable global interrupts

}

void LEDS_Init (void)
{
	DDRC |= (1<<0) | (1<<2) | (1<<3);
	PORTC &= 0xF8;
}

int main (void)
{
	LEDS_Init();
	INT1_Init();


	unsigned char i = 0;


	while(1)
	{
		if (g_i_flag == 0)
		{
			PORTC |= (1<<0);
			_delay_ms(500);
			PORTC &= ~(1<<0);
			_delay_ms(500);

			PORTC |= (1<<1);
			_delay_ms(500);
			PORTC &= ~(1<<1);
			_delay_ms(500);

			PORTC |= (1<<2);
			_delay_ms(500);
			PORTC &= ~(1<<2);
			_delay_ms(500);
		}
		else if (g_i_flag == 1)
		{
			for (i = 0; i < 5; i++)
			{
				PORTC |= (1<<0);
				PORTC |= (1<<1);
				PORTC |= (1<<2);
				_delay_ms(1000);
				PORTC &= ~(1<<0);
				PORTC &= ~(1<<1);
				PORTC &= ~(1<<2);
				_delay_ms(1000);
			}

			g_i_flag = 0;

		}
	}
}
