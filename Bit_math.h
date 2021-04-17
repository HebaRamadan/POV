/*
 *********** Bit_math.h
 *********** Author			: Fadya Kamal , Heba Ramadan , Heba Tharwat
 *********** Created on	    :  1 / 1 / 2021
 *********** Version		:  1
 */

#ifndef BIT_MATH_H_
#define BIT_MATH_H_

#define SET_BIT(Reg , Bit)		 Reg |= (1<<Bit)
#define CLR_BIT(Reg , Bit) 		 Reg &= ~(1<<Bit)
#define GET_BIT(Reg , Bit) 		 ((Reg>>Bit)&1)
#define TOGGLE_BIT(Reg , Bit) 	 Reg ^= (1<<Bit)

#endif /* BIT_MATH_H_ */
