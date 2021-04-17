/*
 *********** Timer1_Interface.h
 *********** Author		    : Fadya Kamal , Heba Ramadan , Heba Tharwat
 *********** Created on	    :  1 / 1 / 2021
 *********** Version		:  1
 */

#ifndef TIMER1_INTERFACE_H_
#define TIMER1_INTERFACE_H_

void Timer1_vidInit(void);

void Timer1_vidSetTCNT1Value(u16 Value);
void Timer1_vidSetOCR1Value (u16 Value);

u16  Timer1_u16GetTCNT1Value(void);
u16  Timer1_u16GetICR1Value (void);

void Timer1_vidSetCallBackOVF     (void(*pf)(void));
void Timer1_vidSetCallBackCMP_A   (void(*pf)(void));
void Timer1_vidSetCallBackCMP_B   (void(*pf)(void));
void Timer1_vidSetCallBackInputCAP(void(*pf)(void));

void GIE_vidEnable (void);
void GIE_vidDisable(void);

void Timer1_vidStopTimer(void);


#endif /* TIMER1_INTERFACE_H_ */
