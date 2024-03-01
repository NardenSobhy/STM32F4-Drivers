/******************************************************************************
 *
 * Module: NVIC
 *
 * File Name: NVIC_interface.h
 *
 * CREATE: 15/12/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 #ifndef NVIC_INTERFACE_H
 #define NVIC_INTERFACE_H
 
 #include "STD_TYPES.h"
 #include "NVIC_private.h"
 #include "NVIC_config.h"
 
 
 
 #define  _GROUP_4_SUB_0						0U
 #define  _GROUP_3_SUB_1						1U
 #define  _GROUP_2_SUB_2						2U
 #define  _GROUP_1_SUB_3						3U
 #define  _GROUP_0_SUB_4						4U
 
 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
 /*		Function: Enables an interrupt or exception.	 
  * -------> ISERx		need Interrput Number	From Vector Table Referance Manual			
  */
void MNVIC_vEnableINT (uint8 Copy_u8IntNUM);


/*	Function: 
 *  Disables an interrupt or exception.			
 */
void MNVIC_vDisableINT (uint8 Copy_u8IntNUM);


/* Function: 
 * Sets the pending status of interrupt or exception to 1.
 */							
void MNVIC_vSetPendingFlag (uint8 Copy_u8IntNUM);

/* Function: 
 * Clears the pending status of interrupt or exception to 0.
 */	
void MNVIC_vClearPendingFlag (uint8 Copy_u8IntNUM);


/* Function: 
 * Reads the pending status of interrupt or exception. 
 * This function returns nonzero value if the pending status is set to 1.
 */	
 uint8 MNVIC_u8GetPendingFlag (uint8 Copy_u8IntNUM);

/* Function: 
 * Reads the Active status of interrupt or exception. 
 * This function returns nonzero value if the Active status is set to 1.
 */	
 uint8 MNVIC_u8GetActiveFlag(uint8 Copy_u8IntNUM);
 
 


void MNVIC_vEnablePeripheral (uint8 Copy_u8INTID);


void MNVIC_vDisablePeripheral (uint8 Copy_u8INTID);


/* Function: 
 * Sets the priority of an interrupt or exception with configurable priority level to 1.
 */	
void MNVIC_vSetPriority (uint8 Copy_u8INTID, uint32 Copy_Priority);

/* Function: 
 * Reads the priority of an interrupt or exception with configurable priority level.
 * This function return the current priority level.
 */	
void MNVIC_vGetPriority (uint8 Copy_u8INTID);


void MNVIC_vConfigGroupSub (uint8 Copy_u8ConfigGroupSub);
 
 
 #endif