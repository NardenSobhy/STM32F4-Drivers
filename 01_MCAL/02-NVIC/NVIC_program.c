/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_program.c
 *
 * CREATE: 15/12/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 
 
 /*===========   INCLUDE LIB   ===========*/
		#include "STD_TYPES.h"
		#include "COMMON_MACROS.h"
  
 /*===========  INCLUDE MCAL  ===========*/
 		#include "NVIC_private.h"
		#include "NVIC_interface.h"
		#include "NVIC_config.h"
 
 
 
 /*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
 /*	Function:  Enables an interrupt or exception.	 
  *  -------> ISERx		need Interrput Number	From Vector Table Referance Manual			
  */
 void MNVIC_vEnableINT (uint8 Copy_u8IntNUM)
 {
	
	if( Copy_u8IntNUM < 32U)
	{
		NVIC_ISER0 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 64U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 32;
		NVIC_ISER1 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 86U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 64;
		NVIC_ISER2 =(1U<<Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}
 }


 /*	Function: 
 *  Disables an interrupt or exception.			
 */
 void MNVIC_vDisableINT (uint8 Copy_u8IntNUM)
 {
	if( Copy_u8IntNUM < 32U)
	{
		NVIC_ICER0 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 64U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 32;
		NVIC_ICER1 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 86U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 64;
		NVIC_ICER2 =(1U<<Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}	
 }

 /* Function: 
 * Sets the pending status of interrupt or exception to 1.
 */	
 void MNVIC_vSetPendingFlag (uint8 Copy_u8IntNUM)
 {
	if( Copy_u8IntNUM < 32U)
	{
		NVIC_ISPR0 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 64U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 32;
		NVIC_ISPR1 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 86U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 64;
		NVIC_ISPR2 =(1U<<Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}	
 }

 /* Function: 
 * Clears the pending status of interrupt or exception to 0.
 */	
 void MNVIC_vClearPendingFlag (uint8 Copy_u8IntNUM)
 {
	if( Copy_u8IntNUM < 32U)
	{
		NVIC_ICPR0 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 64U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 32;
		NVIC_ICPR1 =(1U<<Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 86U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 64;
		NVIC_ICPR2 =(1U<<Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}
 }
 
 /* Function: 
 * Reads the pending status of interrupt or exception. 
 * This function returns nonzero value if the pending status is set to 1.
 */	
 uint8 MNVIC_u8GetPendingFlag (uint8 Copy_u8IntNUM)
 {
 	uint8 L_u8PendingFlag = 0;
	if( Copy_u8IntNUM < 32U)
	{
		L_u8PendingFlag = GET_BIT(NVIC_IABR0,Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 64U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 32;
		L_u8PendingFlag = GET_BIT(NVIC_IABR1,Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 86U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 64;
		L_u8PendingFlag = GET_BIT(NVIC_IABR2,Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}
	return L_u8PendingFlag;
 }
 
 /* Function: 
 * Reads the Active status of interrupt or exception. 
 * This function returns nonzero value if the Active status is set to 1.
 */	
 uint8 MNVIC_u8GetActiveFlag(uint8 Copy_u8IntNUM)
 {
	uint8 L_u8ActiveState = 0;
	if( Copy_u8IntNUM < 32U)
	{
		L_u8ActiveState = GET_BIT(NVIC_IABR0,Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 64U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 32;
		L_u8ActiveState = GET_BIT(NVIC_IABR1,Copy_u8IntNUM);
	}
	else if ( Copy_u8IntNUM < 86U)
	{
		Copy_u8IntNUM = Copy_u8IntNUM - 64;
		L_u8ActiveState = GET_BIT(NVIC_IABR2,Copy_u8IntNUM);
	}
	else
	{
		/* Return Error */
	}
	return L_u8ActiveState;		
 }
 


 /* Function: 
 * Sets the priority of an interrupt or exception 
 * with configurable priority level to 1.
 */
void MNVIC_vSetPriority (uint8 Copy_u8IntNUM, uint32 Copy_Priority)
{
	if( Copy_u8IntNUM <= NUMBER_OF_INTERRUPTS && Copy_Priority <= NVIC_MAX_PRIORITY ) 
	{
		uint8 Local_Index = Copy_u8IntNUM / 4;
		NVIC_IPR_BASE_ADDRESS[Local_Index] =  (Copy_Priority << 4);
		SCB_AIRCR = _0GROUP_16SUB;
	}
	else
	{
		/* Return Error */	
	}
	
}

 /* Function: 
 * Reads the priority of an interrupt or exception with configurable priority level.
 * This function return the current priority level.
 */
void MNVIC_vGetPriority (uint8 Copy_u8INTID)
{
	
	
}


void MNVIC_vConfigGroupSub (uint8 Copy_u8ConfigGroupSub)
{
	
	
}

void MNVIC_vEnablePeripheral (uint8 Copy_u8INTID){
	
	
}



void MNVIC_vDisablePeripheral (uint8 Copy_u8INTID)
{
	
	
}