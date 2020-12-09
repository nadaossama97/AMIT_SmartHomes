/*
 * master.c
 *
 * Created: 12/9/2020 12:28:37 AM
 * Author : Nada
 */ 

#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>
#include "UART.h"
#include "SPI.h"
#include "ADC.h"

ISR(ADC_vect)
{
	while(!(ADCSRA &(1<<ADIF)));
	int data = readADC();
	if(data*4.8828215 >300)
	{
		SPI_Master_send('H');
	}
	else
	{
		SPI_Master_send('L');
	}
	ADC_convert();
}


int main(void)
{
	/* Replace with your application code */

	sei();
	SPI_init(SPI_MASTER);
	ADC_init(CH0, AREF_MODE, PreScalar_128);
	UART_init();
	ADC_convert();

	char x;
	while (1)
	{

		x= UART_recieve();
		UART_send(x);
		SPI_Master_send(x);

		
	}
}

