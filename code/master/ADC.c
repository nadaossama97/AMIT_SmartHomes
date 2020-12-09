/*
 * ADC.c
 *
 * Created: 12/9/2020 1:03:56 AM
 *  Author: Nada
 */ 
#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

//Channels
#define CH0             0
#define CH1             1
#define CH2             2
#define CH3             3
#define CH4             4
#define CH5             5
#define CH6             6
#define CH7             7
//References
#define AVCC_MODE       1
#define AREF_MODE       0
#define Internal_MODE   3
//Frequency
#define PreScalar_2     0 
#define PreScalar_4     2
#define PreScalar_8     3
#define PreScalar_16    4
#define PreScalar_32    5
#define PreScalar_64    6
#define PreScalar_128   7

void ADC_Channel(int channelNum)
{
	
	ADMUX |= (channelNum);
	if ( channelNum < 8)
	{
			ADMUX = (ADMUX & 0x0E)|channelNum; 
	}
}
void ADC_Reference(int RefMode)
{
	ADMUX =(ADMUX & 0x3F)|(RefMode<<6);
	
}
void ADC_Frequency(int Prescaler)
{
if (ADCSRA & (1<<ADIE))
{
	ADCSRA &= ~(1<<ADIE);
	ADCSRA =(ADCSRA & 0xF8)|(Prescaler);
	ADCSRA |= (1<<ADIE);
}
else
{
	ADCSRA =(ADCSRA & 0xF8)|(Prescaler);
}
}

void ADC_init(int channelNum, int RefMode, int Prescalar)
{
	ADC_Channel(channelNum);
	ADC_Reference(RefMode);
	ADC_Frequency(Prescalar);
	ADCSRA |= (1<<ADIE); 
	ADCSRA |=(1<<ADEN);
}
void ADC_convert()
{
	ADCSRA |=(1<<ADSC);
}

int readADC()
{
	int val= ADCL;
	val |= (ADCH<<8);
	return val;
}

void waitConversion()
{
	while(!(ADCSRA &(1<<ADIF)));
}
