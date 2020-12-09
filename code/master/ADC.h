/*
 * ADC.h
 *
 * Created: 12/9/2020 1:05:51 AM
 *  Author: Nada
 */ 


#ifndef ADC_H_
#define ADC_H_


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


void ADC_Channel(int channelNum);
void ADC_Reference(int RefMode);
void ADC_Frequency(int Prescaler);
void ADC_init(int , int , int );
void ADC_convert();
int readADC();
void waitConversion();


#endif /* ADC_H_ */