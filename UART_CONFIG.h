/*
 * UART_CONFIG.h
 *
 * Created: 10/4/2020 2:16:59 PM
 *  Author: Mohamed
 */ 

#define  F_CPU 16000000UL
#include "util/delay.h"
#include "avr/io.h"
#include "stdlib.h"
#include "Data_Types.h"

#ifndef UART_CONFIG_H_
#define UART_CONFIG_H_
extern uinteg16_t  MYUBRR;
 void (*ptr_To_TX_Int_fun)(void);/*POINTER TO FUCTION CARRY THE ADRESS OF TX_FUCTION  */
 void (*ptr_To_RX_Int_fun)(void);/*POINTER TO FUCTION CARRY THE ADRESS OF RX_FUCTION  */


enum USART_SYNCH_MODE_{
	USART_ASYNCH_MODE,
	USART_SYNCH_MODE =(1<<6)      /*Bit 6 ? UMSEL: USART Mode Select*/
};

enum USART_SPEED_MODE{
	USART_NORMAL_SPEED,
	USART_DOUBLE_SPEED
};
enum USART_TX{
	USART_TX_DISABLE,
	USART_TX_ENABLE
};
enum USART_RX{
	USART_RX_DISABLE,
	USART_RX_ENABLE
};
enum USART_DATA_FORMAT{
	USART_DATA_FORMAT_5BIT_MODE =(00<<1),
	USART_DATA_FORMAT_6BIT_MODE =(01<<1),
	USART_DATA_FORMAT_7BIT_MODE =(10<<1),
	USART_DATA_FORMAT_8BIT_MODE =(11<<1)
};

enum USART_PARITY_MODE{
	USART_PARITY_DISABLE =(00<<4),
	USART_PARITY_MODE_EVEN   =(01<<4),
	USART_PARITY_MODE_ODD   =(11<<4)
	
};
enum USART_STOP_BITS_NUM{
	USART_1_STOP_BIT =(0<<3),
	USART_2_STOP_BITS =(1<<3)
};
enum USART_TX_INTERRUPT{
	USART_TX_INTERRUPT_DISABLE=(0<<6),
	USART_TX_INTERRUPT_ENABLE=(1<<6)
	
};
enum USART_RX_INTERRUPT{
	USART_RX_INTERRUPT_DISABLE= (0<<7),
	USART_RX_INTERRUPT_ENABLE= (1<<7)
};
/*Bit 5 ? UDRIE: USART Data Register Empty Interrupt Enable*/
enum USART_UDR_INTERRUPT{
	USART_UDR_INTERRUPT_DISABLE= (0<<5),
	USART_UDR_INTERRUPT_ENABLE= (1<<5)
	};

struct USART_Config{
	enum USART_SYNCH_MODE_           SYNCH_MODE;
	enum USART_SPEED_MODE            SPEED_MODE;
	enum USART_TX                   TX_;
	enum USART_RX                   RX_;
	enum USART_DATA_FORMAT          CHAR_SIZE;
	enum USART_PARITY_MODE          PARITY_MODE;
	enum USART_STOP_BITS_NUM        STOP_BITS_NUM;
	enum USART_TX_INTERRUPT         TX_INTERRUPT;
	enum USART_RX_INTERRUPT         RX_INTERRUPT;
	enum USART_UDR_INTERRUPT        UDR_INTERRUPT;
	//INT16U                          BUAD_RATE;
};
extern struct USART_Config USART_PRE_CONFIGRATION;




#endif /* UART_CONFIG_H_ */