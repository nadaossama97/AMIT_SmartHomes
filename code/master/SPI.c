/*
 * SPI.c
 *
 * Created: 12/9/2020 12:45:08 AM
 *  Author: Nada
 */ 
#include <avr/io.h>
#include <stdlib.h>

#define SPI_MASTER  1
#define SPI_SLAVE   0

#define SPI_PS_4
#define SPI_PS_16
#define SPI_PS_64
#define SPI_PS_128
#define SPI_PS_2
#define SPI_PS_8
#define SPI_PS_32

#define SS     4
#define SCK    7
#define MOSI   5
#define MISO   6


void SPI_init(int mode)
{
	// SPI control Register
	if (mode== SPI_MASTER)
	{
		DDRB |= (1<<SS) | (1<< MOSI) | (1<< SCK);
		SPCR |= (1<<MSTR);
	}
	else
	{
		DDRB |= (1<<MISO);
	}

	SPCR |= (1<<SPE) | (1<<SPR1) | (1<<SPR0);
	
}
void SPI_Master_send(char data)
{
	SPDR = data;
	while (!(SPSR & (1<<SPIF)));
	
}
void SPI_Master_send_str(char* str)
{
	for(int i =0; str[i] != '\0'; i++)
	{
		SPI_Master_send(str[i]);
	}
}
void SPI_Master_send_num(int num)
{
	char str[10];
	itoa(num, str, 10);
	SPI_Master_send_str(str);
}

char SPI_SlAVE_recieve()
{
	while (!(SPSR & (1<<SPIF)));
	return SPDR;
}
