/*
 *********** LED_Program.h
 *********** Author		    : Fadya Kamal , Heba Ramadan . Heba Tharwat
 *********** Created on	    :  1 / 1 / 2021
 *********** Version		:  1
 */

#include "Std_types.h"
#include "Bit_math.h"
#include "DIO_Interface.h"

void LEDS_vidInit(void)
{

	DIO_vidSetPinDirection(PortA , PIN_4 , DIO_OUTPUT);
	DIO_vidSetPinDirection(PortA , PIN_6 , DIO_OUTPUT);
	DIO_vidSetPinDirection(PortA , PIN_7 , DIO_OUTPUT);

	DIO_vidSetPinDirection(PortB , PIN_6 , DIO_OUTPUT);

	DIO_vidSetPinDirection(PortC , PIN_0 , DIO_OUTPUT);
	DIO_vidSetPinDirection(PortC , PIN_1 , DIO_OUTPUT);

	DIO_vidSetPinDirection(PortD , PIN_4 , DIO_OUTPUT);
	DIO_vidSetPinDirection(PortD , PIN_5 , DIO_OUTPUT);

	/* Hall Sensor PIN */
	DIO_vidSetPinDirection(PortD , PIN_6 , DIO_INPUT );
	DIO_vidSetPinValue(PortD , PIN_6 , DIO_HIGH);


}

void LEDS_vidSetPattern(u8 value)
{
	DIO_vidSetPinValue( PortA , PIN_4 , GET_BIT(value , 0));
	DIO_vidSetPinValue( PortB , PIN_6 , GET_BIT(value , 1));
	DIO_vidSetPinValue( PortA , PIN_6 , GET_BIT(value , 2));
	DIO_vidSetPinValue( PortA , PIN_7 , GET_BIT(value , 3));

	DIO_vidSetPinValue( PortC , PIN_0 , GET_BIT(value , 4));
	DIO_vidSetPinValue( PortC , PIN_1 , GET_BIT(value , 5));

	DIO_vidSetPinValue( PortD , PIN_4 , GET_BIT(value , 6));
	DIO_vidSetPinValue( PortD , PIN_5 , GET_BIT(value , 7));


}

void LEDS_vidClearPattern(void)
{

	DIO_vidSetPinValue( PortA , PIN_4 , DIO_LOW);
	DIO_vidSetPinValue( PortB , PIN_6 , DIO_LOW);
	DIO_vidSetPinValue( PortA , PIN_6 , DIO_LOW);
	DIO_vidSetPinValue( PortA , PIN_7 , DIO_LOW);

	DIO_vidSetPinValue( PortC , PIN_0 , DIO_LOW);
	DIO_vidSetPinValue( PortC , PIN_1 , DIO_LOW);

	DIO_vidSetPinValue( PortD , PIN_4 , DIO_LOW);
	DIO_vidSetPinValue( PortD , PIN_5 , DIO_LOW);
}
