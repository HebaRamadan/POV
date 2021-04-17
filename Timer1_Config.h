/*
 * Timer1_Config.h
 *********** Author		    : Fadya Kamal , Heba Ramadan , Heba Tharwat
 *********** Created on	    :  1 / 1 / 2021
 *********** Version		:  1
 */

#ifndef TIMER1_CONFIG_H_
#define TIMER1_CONFIG_H_


#define TIMER1_u8NORMAL_MODE              	    1
#define TIMER1_u8CTC_MODE_TOP_OCR1_OVMAX		2
#define TIMER1_u8CTC_MODE_TOP_ICR1_OVMAX		3
#define TIMER1_u8FAST_PWM_MODE_TOP_OCR1_OVTOP	4
#define TIMER1_u8FAST_PWM_MODE_TOP_ICR1_OVTOP	5
#define TIMER1_u8FAST_PWM_MODE_8BIT       	  	6
#define TIMER1_u8FAST_PWM_MODE_9BIT       	  	7
#define TIMER1_u8FAST_PWM_MODE_10BIT      	  	8
#define TIMER1_u8INPUTCAPTURREMODE              9


#define TIMER1_u8OC1_DISCONNECTED 		   	   	1
#define TIMER1_u8TOGGLE_OC1_ON_CM  	       		2
#define TIMER1_u8CLEAR_OC1_ON_CM_SET_ON_TOP 	3
#define TIMER1_u8SET_OC1_ON_CM_CLEAR_ON_TOP 	4
#define TIMER1_CHANNEL_DISCONECTED				5


#define TIMER1_u8FCPU_1      					1
#define TIMER1_u8FCPU_8      					2
#define TIMER1_u8FCPU_64     					3
#define TIMER1_u8FCPU_256    					4
#define TIMER1_u8FCPU_1024   					5
#define TIMER1_u8FCPU_EXTERNAL_CLK_FALLING  	6
#define TIMER1_u8FCPU_EXTERNAL_CLK_RISING   	7




/************************************
 * Waveform Generation Mode:
 * Select one of the following:
 * TIMER1_u8NORMAL_MODE
 * TIMER1_u8CTC_MODE_TOP_OCR1_OVMAX
 * TIMER1_u8CTC_MODE_TOP_ICR1_OVMAX
 * TIMER1_u8FAST_PWM_MODE_TOP_OCR1_OVTOP
 * TIMER1_u8FAST_PWM_MODE_TOP_ICR1_OVTOP
 * TIMER1_u8FAST_PWM_MODE_8BIT
 * TIMER1_u8FAST_PWM_MODE_9BIT
 * TIMER1_u8FAST_PWM_MODE_10BIT
 * TIMER1_u8INPUTCAPTURREMODE
 * for ex. #define TIMER1_u8WFG_MODE  TIMER1_u8CTC_MODE_TOP_OCR1
 ************************************/
#define TIMER1_u8WFG_MODE  TIMER1_u8NORMAL_MODE



/************************************
 * Compare Match Output Mode:
 * Select one of the following:
 * TIMER1_u8OC1_DISCONNECTED
 * TIMER1_u8TOGGLE_OC1_ON_CM
 * TIMER1_u8CLEAR_OC1_ON_CM_SET_ON_TOP
 * TIMER1_u8SET_OC1_ON_CM_CLEAR_ON_TOP
 * TIMER1_CHANNEL_DISCONECTED
 * for ex. #define TIMER1_u8CHANNELA_COM  TIMER1_u8TOGGLE_OC1_ON_CM
 * for ex. #define TIMER1_u8CHANNELB_COM  TIMER1_CHANNEL_DISCONECTED
 ************************************/
#define TIMER1_u8CHANNELA_COM  TIMER1_CHANNEL_DISCONECTED
#define TIMER1_u8CHANNELB_COM  TIMER1_CHANNEL_DISCONECTED



/************************************
 * TIMER1 Pre_Scaler:
 * Select one of the following:
 * TIMER1_u8FCPU_1
 * TIMER1_u8FCPU_8
 * TIMER1_u8FCPU_64
 * TIMER1_u8FCPU_256
 * TIMER1_u8FCPU_1024
 * TIMER1_u8FCPU_EXTERNAL_CLK_FALLING
 * TIMER1_u8FCPU_EXTERNAL_CLK_RISING
 * for ex. #define TIMER1_u8PRESCALLER_VALU  TIMER1_u8FCPU_8
 ************************************/
#define TIMER1_u8PRESCALLER_VALU  TIMER1_u8FCPU_1


#define TIMER1_u16PRELOAD                   0
#define TIMER1_u16COMPARE_VALUE_CHANNELA    0
#define TIMER1_u16COMPARE_VALUE_CHANNELB    0
#define TIMER1_u16INPUT_CAPTURE_VALUE       0

#endif /* TIMER1_CONFIG_H_ */
