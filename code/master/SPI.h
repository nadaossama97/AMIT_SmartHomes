/*
 * SPI.h
 *
 * Created: 12/9/2020 12:45:49 AM
 *  Author: Nada
 */ 


#ifndef SPI_H_
#define SPI_H_

#define SPI_MASTER  1
#define SPI_SLAVE   0

#define SPI_PS_4
#define SPI_PS_16
#define SPI_PS_64
#define SPI_PS_128
#define SPI_PS_2
#define SPI_PS_8
#define SPI_PS_32

void SPI_init(int );
void SPI_Master_send(char );
void SPI_Master_send_str(char* );
void SPI_Master_send_num(int );
char SPI_SlAVE_recieve();




#endif /* SPI_H_ */