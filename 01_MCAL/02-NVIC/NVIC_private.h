 /******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_private.h
 *
 * CREATE: 15/12/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 #ifndef NVIC_PRIVATE_H
 #define NVIC_PRIVATE_H
 
 /*=================================================================================
	-----> Macros
			*  Base_Address NVIC				
=================================================================================*/

 #define MNVIC_BASE_ADDRESS 		0xE000E100
 
 /*=================================================================================
	-----> Macros
			  *  Register Map	NVIC	
===================================================================================*/
 
/******************************* NVIC ISER REGISTERS **********************************/

#define NVIC_ISER0				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x100) ))) /* INTERRUPT SET-ENABLE REGISTERS from 0  to 31 */ 
#define NVIC_ISER1				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x104) ))) /* INTERRUPT SET-ENABLE REGISTERS from 32 to 63 */
#define NVIC_ISER2				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x108) ))) /* INTERRUPT SET-ENABLE REGISTERS from 64 to 95 */
  
/******************************** NVIC ICER REGISTERS *********************************/

#define NVIC_ICER0				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x180) ))) /* INTERRUPT CLEAR ENABLE REGISTERS from 0  to 31 */ 
#define NVIC_ICER1				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x184) ))) /* INTERRUPT CLEAR ENABLE REGISTERS from 32 to 63 */
#define NVIC_ICER2				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x188) ))) /* INTERRUPT CLEAR ENABLE REGISTERS from 64 to 95 */
 
/******************************** NVIC ISPR REGISTERS *********************************/

#define NVIC_ISPR0 				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x200) ))) /* INTERRUPT SET-PENDING REGISTERS from 0  to 31 */ 
#define NVIC_ISPR1 				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x204) ))) /* INTERRUPT SET-PENDING REGISTERS from 32 to 63 */
#define NVIC_ISPR2 				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x208) ))) /* INTERRUPT SET-PENDING REGISTERS from 64 to 95 */
 
/******************************** NVIC ICPR REGISTERS *********************************/

#define NVIC_ICPR0 				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x280) ))) /* INTERRUPT CLEAR-PENDING REGISTERS from 0  to 31 */ 
#define NVIC_ICPR1 				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x284) ))) /* INTERRUPT CLEAR-PENDING REGISTERS from 32 to 63 */
#define NVIC_ICPR2 				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x288) ))) /* INTERRUPT CLEAR-PENDING REGISTERS from 64 to 95 */
							
/******************************** NVIC IABR REGISTERS *********************************/

#define NVIC_IABR0 				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x300) ))) /* INTERRUPT ACTIVE BIT REGISTERS from 0  to 31 */ 
#define NVIC_IABR1 					(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x304) ))) /* INTERRUPT ACTIVE BIT REGISTERS from 32 to 63 */
#define NVIC_IABR2 				 	(*((volatile uint32*)( (MNVIC_BASE_ADDRESS) + (0x308) ))) /* INTERRUPT ACTIVE BIT REGISTERS from 64 to 95 */

/******************************** NVIC IPR REGISTERS *********************************/
#define NVIC_IPR_BASE_ADDRESS   	(( volatile uint8* )( (MNVIC_BASE_ADDRESS) + (0x400) ))
 
  
  
/*=================================================================================
	-----> Macros
			*  Base_Address SCB(SYSTEM CONTROL BLOCK)				
=================================================================================*/

#define  SCB_Base_Address			0xE000ED00	


/*=================================================================================
	-----> Macros
		*  Register Map SCB ---------> AIRCR To Submet The Group & SubGroup
		* Statuse Of Group And Sub Application interrupt and reset control register (AIRCR)	
===================================================================================*/

#define  SCB_AIRCR 					(*((volatile uint32 *) ( (SCB_Base_Address) + (0x0C))))
 

#define _0GROUP_16SUB 				0x05FA0700 
 #endif