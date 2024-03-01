/******************************************************************************
 *
 * Module: DELAY
 *
 * File Name: DELAY_interface.c
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 

/*============= INCLUDE LIB ==============*/
	 #include "STD_TYPES.h"
	 #include "BIT_MATH.h"
/*========================================*/	 

/*============= INCLUDE MCAL ==============*/

	#include "Delay_interface.h"
	
/*========================================*/	


/*======================================================== Start_FUNCTION  ========================================================*/
/*
*		Function To Delay By Milliseconds ( 16MHz CPU CLK )
*/

extern void Delay_voidMsIn16MHz(uint16 copy_u16CountNum)
{
	volatile uint16 u16Local_Count1 ;
	volatile uint16 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < 3180  ; u16Local_Count2 ++ )
	{} // Do nothing for 1 ms
}



/*======================================================== END_ FUNCTION   ========================================================*/



/*======================================================== Start_FUNCTION  ========================================================*/
/*
*		Function To Delay By Microseconds ( 16MHz CPU CLK )
*/

extern void Delay_voidUsIn16MHzint (uint16 copy_u16CountNum)
{
	volatile uint16 u16Local_Count1 ;
	volatile uint16 u16Local_Count2 ;
	for(u16Local_Count1 = 0 ; u16Local_Count1 < copy_u16CountNum  ; u16Local_Count1++ )
	for(u16Local_Count2  = 0 ; u16Local_Count2  < 3  ; u16Local_Count2 ++ )
	{} // Do nothing for 1 ms
}
/*======================================================== END_ FUNCTION   ========================================================*/