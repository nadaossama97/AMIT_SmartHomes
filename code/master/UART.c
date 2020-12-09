/*
 * UART.c
 *
 * Created: 12/9/2020 1:07:15 AM
 *  Author: Nada
 */ 
#include <avr/io.h>
#include <stdlib.h>

void UART_init()
{
	UCSRB |= (1<<TXEN)| (1<<RXEN);
	UBRRL = 103;
}

void UART_send(char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}

void UART_send_str(char* str)
{
	for (int i=0; str[i]!= '\0'; i++)
	{
		UART_send(str[i]);
	}
}
void UART_send_num(int num)
{
	char str[10];
	itoa(num, str, 10);
	UART_send_str(str);
}

char UART_recieve()
{
	while(!(UCSRA & (1<< RXC)));
	return UDR;
}
