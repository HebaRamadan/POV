/*
 *********** main.c
 *********** Timer1_Program.c
 *********** Author		    : Fadya Kamal , Heba Ramadan , Heba Tharwat
 *********** Created on	    :  7 / 1 / 2021
 *********** Version		:  1
 */
#include "Std_types.h"
#include "Bit_math.h"
#include "Timer1_Interface.h"
#include "LED_Interface.h"


void App_vidTimer1OverFlow(void);
void App_vidHallSensor    (void);
void App_vidDisplayPattern(void);

u8   POV_DisplayCounter = 0;
u16  OverFlowCounter    = 0;
u32  POV_PatternStep    = 0;

u8   PovDisplayArray[64]={
						   0x83 , 0x83 , 0xff , 0x83 , 0x83 , 0x01 ,  //I
						   0x03 , 0x03 , 0xff , 0x03 , 0x03 , 0x01 ,  //T
						   0x83 , 0x83 , 0xff , 0x83 , 0x83 , 0x01 ,  //I

						   0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,

						   0x85 , 0xc3 , 0xa3 , 0x93 , 0x8d , 0x01 ,  //2
						   0x7d , 0xa3 , 0x93 , 0x8b , 0x7d , 0x01 ,  //0
						   0x85 , 0xc3 , 0xa3 , 0x93 , 0x8d , 0x01 ,  //2
						   0x7d , 0xa3 , 0x93 , 0x8b , 0x7d , 0x01 ,  //0

						   0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
						   0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,
						   0x01 , 0x01 , 0x01 , 0x01
						  };



/*char PovDisplayArray[64]={
						   0xff , 0x13 , 0x13 , 0x13 , 0x13 , 0x01 ,//F
						   0x83 , 0x83 , 0xff , 0x83 , 0x83 , 0x01 ,//I
						   0x7d , 0x83 , 0x93 , 0x93 , 0x75 , 0x01 ,//G
						   0xff , 0x11 , 0x11 , 0x11 , 0xff , 0x01 ,//H
						   0x03 , 0x03 , 0xff , 0x03 , 0x03 , 0x01 ,//T
                           0xff , 0x93 , 0x93 , 0x93 , 0x93 , 0x01 ,//E
						   0xff , 0x13 , 0x33 , 0x53 , 0x8d , 0x01 ,//R
						   0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,//1s
						   0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,//1s
						   0x01 , 0x01 , 0x01 , 0x01 , 0x01 , 0x01 ,//1s
						   0x01 , 0x01 , 0x01 , 0x01
						  };*/


int main(void)
{
	Timer1_vidSetCallBackOVF      (  &App_vidTimer1OverFlow );
	Timer1_vidSetCallBackInputCAP (  &App_vidHallSensor     );
	Timer1_vidSetCallBackCMP_A    (  &App_vidDisplayPattern );

	LEDS_vidInit  ();
	Timer1_vidInit();
	GIE_vidEnable ();


	while(1);


	return 0;
}




void App_vidTimer1OverFlow(void)
{
	OverFlowCounter++;
}


void App_vidHallSensor    (void)
{
	/* Clear TCNT1 */
	Timer1_vidSetTCNT1Value(0);

	/* Get ICR Register Value To determine number of counts for one revolution */
	u16 ICR1_Val = Timer1_u16GetICR1Value();

	/* Number of counts for one step to display pattern                        */
	POV_PatternStep = ( ICR1_Val + (OverFlowCounter * 65536) ) / 64;

	/* Set OCR1 with counts for one step to display pattern                    */
	Timer1_vidSetOCR1Value((u16)POV_PatternStep);

	/* Reset Overflow Counter         */
	OverFlowCounter    = 0;

	/* Reset Display pattern Counter  */
	POV_DisplayCounter = 0;

}


void App_vidDisplayPattern(void)
{
	/* Calculate number of counts for next pattern */
	u16 Step = Timer1_u16GetTCNT1Value() + (u16)POV_PatternStep ;

	/* Re-initiate OCR register for next pattern    */
	Timer1_vidSetOCR1Value( Step );

	/* Check Display Counter                        */
	if( POV_DisplayCounter < 64 )
	{
		/* Display Pattern in Our POV				*/
		LEDS_vidSetPattern( PovDisplayArray[ POV_DisplayCounter ] );
	}
	else
	{
		/* Clear this pattern in POV				*/
		LEDS_vidClearPattern();
	}

	/* Increase Display Counter for next pattern	*/
	POV_DisplayCounter++;


}


