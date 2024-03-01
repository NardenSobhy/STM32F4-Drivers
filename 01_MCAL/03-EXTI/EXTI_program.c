/******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_program.c
 *
 * CREATE: 20/2/2024
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 
 /*===========   INCLUDE LIB   ===========*/
		#include "STD_TYPES.h"
		#include "COMMON_MACROS.h"
  
 /*===========  INCLUDE MCAL  ===========*/
 		#include "EXTI_private.h"
		#include "EXTI_interface.h"
		#include "EXTI_config.h"
 
 
 /*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
 void (*EXTI0_CallBack )(void);
 
 
 /** Function: Enable an external interrupt line.
 *	This function enable the specified external interrupt line, allowing it to trigger
 * 	interrupt requests.
 */
 void MEXTI_vEnableLine(uint8 Copy_u8LineNUM )
 {
	if (Copy_u8LineNUM < EXTI_LINES_COUNT)
	{
		SET_BIT(EXTI -> IMR,Copy_u8LineNUM);
	}
	else 
	{
		/* Return Error */
	}
	
 }
 
 /** Function: Disable an external interrupt line.
 *	This function disables the specified external interrupt line, preventing it from
 * 	triggering interrupt requests.
 */
void MEXTI_vDisableLine(uint8 Copy_u8LineNUM)
{
	if (Copy_u8LineNUM < EXTI_LINES_COUNT)
	{
		CLEAR_BIT(EXTI -> IMR,Copy_u8LineNUM);
	}
	else 
	{
		/* Return Error */
	}
	
 }
 
 /** Function: Set the trigger mode for an external interrupt line.
 *  This function configures the trigger mode for the specified external interrupt line.
 *  The trigger mode determines whether the interrupt is triggered on a rising edge,
 *  falling edge, or both edges of the corresponding signal.
 */
 
 void MEXTI_vSetTrigger(uint8 Copy_u8LineNUM , uint8 Copy_Mode )
 {
	if (Copy_u8LineNUM < EXTI_LINES_COUNT)
	{
		switch(Copy_Mode)
		{
			case _RAISE_STATE:
				SET_BIT(EXTI->RTSR ,Copy_u8LineNUM );
				CLR_BIT(EXTI->FTSR ,Copy_u8LineNUM ); 
				break;
			case _FALL_STATE
				SET_BIT(EXTI->FTSR ,Copy_u8LineNUM );
				CLR_BIT(EXTI->RTSR ,Copy_u8LineNUM ); 
				break;
			case _ON_CHANGE_STATE
				SET_BIT(EXTI->RTSR ,Copy_u8LineNUM );
				SET_BIT(EXTI->FTSR ,Copy_u8LineNUM ); 
				break;
			default:
                /* Invalid trigger mode, return error or handle accordingly */
            break;
	}
	else 
	{
		/* Return Error */
	}
 }
 
 
  /** Function: Generate a software interrupt on an external interrupt line.
 *   This function generates a software interrupt on a specified external interrupt line.
 *   The function sets the corresponding bit in the EXTI_SWIER register to trigger a software interrupt on the line.
 */
 void MEXTI_vSoftwareInterrupt(uint8 Copy_u8LineNUM  )
{
	if (Copy_u8LineNUM < EXTI_LINES_COUNT)
	{
		SET_BIT(EXTI->SWIER ,Copy_u8LineNUM );
	}
	else 
	{
		/* Return Error */
	}
}

/** Function: Configure the EXTI line to a specific GPIO port.
 * This function configures an EXTI line to use a specific GPIO port.
 * Copy_u8LineNUM is the EXTI line number to configure (e.g., MEXTI_LINE_0, MEXTI_LINE_1).
 * Copy_u8PortID is the GPIO port to associate with the EXTI line.
 * The function configures the SYSCFG_EXTICR registers based on the provided EXTI line number and GPIO port.
 */
 void MEXTI_vSetEXTIConfig(uint8 Copy_u8LineNUM , uint8 Copy_u8PortID )
 {
	if(Copy_u8LineNUM  <= 3U)
	{
		/* Safty --> 0000 */
		SYSCFG_EXTICR1 &=~(0b1111 <<(4U*Copy_u8LineNUM));
		SYSCFG_EXTICR1 |=(Copy_u8PortID <<(4U*Copy_u8LineNUM));
		
	}
	// 4 == 0
	else if (Copy_u8LineNUM  <= 7U)
	{
		Copy_u8LineNUM -=4 ;
		/* Safty --> 0000 */
		SYSCFG_EXTICR2 &=~(0b1111 <<(4U*Copy_u8LineNUM));
		SYSCFG_EXTICR2 |=(Copy_u8PortID <<(4U*Copy_u8LineNUM));
		
	}
	// 4 == 0
	else if (Copy_u8LineNUM  <= 11U)
	{
		Copy_u8LineNUM -=8 ;
		/* Safty --> 0000 */
		SYSCFG_EXTICR3 &=~(0b1111 <<(4U*Copy_u8LineNUM));
		SYSCFG_EXTICR3 |=(Copy_u8PortID <<(4U*Copy_u8LineNUM));
		
	}
	else if (Copy_u8LineNUM  <= 15U)
	{
		Copy_u8LineNUM -=12 ;
		/* Safty --> 0000 */
		SYSCFG_EXTICR4 &=~(0b1111 <<(4U*Copy_u8LineNUM));
		SYSCFG_EXTICR4 |=(Copy_u8PortID <<(4U*Copy_u8LineNUM));
		
	}else
	{
		/* Return Error */
	}
}


/** Function: Check the pending state of a specific external interrupt line
 */
uint8 MEXTI_vGetPending(uint8 Copy_u8LineNUM  )
{
	uint8 L_u8PendingState = 0U ;
	L_u8PendingState = GET_BIT( EXTI -> PR,Copy_u8LineNUM);
	return L_u8PendingState ; 
}


/********************************/
//elmfroof ykon feh mnha 16 as there is 16 extenal interrupt line


void EXTI0_vSetCallBack( void (*ptr)(void) )
{
	EXTI0_CallBack = ptr ;
}


void EXTI0_IRQHandler(void)  
{
	// clear PR Flag for EXTI0 by writing 1 on it, without clearing it will do interrupt always
	// we may need to leave the flag without clearing, to avoid sniffing on the system, and keep system in thread
	SET_BIT(MEXTI->EXTI_PR, 0);
	EXTI0_CallBack();
	
}

/*********************************/