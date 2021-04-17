/*
 *********** DIO_Interface.h
 *********** Author			: Fadya Kamal , Heba Ramadan , Heba Tharwat
 *********** Created on	    :  1 / 1 / 2021
 *********** Version		:  1
 */


#ifndef  DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


#define PortA			0
#define PortB			1
#define PortC			2
#define PortD			3

#define PIN_0			0
#define PIN_1			1
#define PIN_2			2
#define PIN_3			3
#define PIN_4			4
#define PIN_5			5
#define PIN_6			6
#define PIN_7			7

#define DIO_INPUT		0
#define DIO_OUTPUT		1

#define DIO_LOW			0
#define DIO_HIGH		1


void DIO_vidSetPinDirection		( u8 Copy_U8Port  ,  u8 Copy_U8Pin  ,  u8 Copy_U8Direction);
void DIO_vidSetPinValue			( u8 Copy_U8Port  ,  u8 Copy_U8Pin  ,  u8 Copy_U8Value     );
u8   DIO_u8GetPinValue    	 	( u8 Copy_U8Port  ,  u8 Copy_U8Pin	);

void DIO_vidSetPortDirection	( u8 Copy_U8Port  ,  u8 Copy_U8Direction	);
void DIO_vidSetPortValue		( u8 Copy_U8Port  ,  u8 Copy_U8Value		);
void DIO_vidTogglePin			( u8 Copy_U8Port  ,  u8 Copy_U8Pin			);



#endif 
