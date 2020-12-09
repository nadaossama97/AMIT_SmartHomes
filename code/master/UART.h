/*
 * UART.h
 *
 * Created: 12/9/2020 1:08:11 AM
 *  Author: Nada
 */ 


#ifndef UART_H_
#define UART_H_


void UART_init();
void UART_send(char data);
void UART_send_str(char* str);
void UART_send_num(int );

char UART_recieve();


#endif /* UART_H_ */