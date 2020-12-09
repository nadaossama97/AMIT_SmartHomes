/*
 * slave.c
 *
 * Created: 12/9/2020 12:26:34 AM
 * Author : Nada
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include "SPI.h"


int main(void)
{
	/* Replace with your application code */
	SPI_init(SPI_SLAVE);
	_delay_ms(10);
	DDRC = 0xFF;
	DDRD = 0xFF;
	char x;
	while (1)
	{
		x= SPI_SlAVE_recieve();
		if(x == '1')
		{
			PORTC |= (1<<0);  // BLUE LED IS ON
			
		}
		else if (x == '2')
		{
			PORTC &=~ (1<<0);  // BLUE LED IS OFF
		}
		else if (x == '3')
		{
			PORTD |= (1<<0);  // RED LED IS ON
		}
		else if (x == '4')
		{
			PORTD &= ~(1<<0);  // RED LED IS OFF
		}
		else if (x == 'L')
		{
			PORTD &= ~(1<<7);  // Fan OFF
		}
		else if (x == 'H')
		{
			PORTD |= (1<<7); // Fan ON
		}
		else
		{
			
		}
	}
}
