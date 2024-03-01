 /******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_private.h
 *
 * CREATE: 20/2/2024
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 #ifndef EXTI_PRIVATE_H
 #define EXTI_PRIVATE_H
 
 #include "STD_TYPES.h"
 
/*=================================================================================
	-----> Macros
			*  Base_Address EXTI				
=================================================================================*/

 #define _EXTI_BASE_ADDRESS 0x4001 3C00 
 
 /* EXTI register structure */
 
 typedef struct
 {
	volatile uint32 IMR   ;      /*!< EXTI Interrupt mask register,            Address offset: 0x00 */
	volatile uint32 EMR   ;      /*!< EXTI Event mask register,                Address offset: 0x04 */
	volatile uint32 RTSR  ;      /*!< EXTI Rising trigger selection register,  Address offset: 0x08 */
	volatile uint32 FTSR  ;      /*!< EXTI Falling trigger selection register, Address offset: 0x0C */
	volatile uint32 SWIER ;      /*!< EXTI Software interrupt event register,  Address offset: 0x10 */
	volatile uint32 PR    ;      /*!< EXTI Pending register,                   Address offset: 0x14 */
	
	
 }EXTI_t;
 
 /* Pointer to EXTI register structure */
 #define EXTI                  ((EXTI_t *)(_EXTI_BASE_ADDRESS ))
 
 /*Total number of EXTI register structure */
 #define EXTI_LINES_COUNT 		16	
 
 #define _SYSCFG_BASE_ADDRESS    0x40013800 

 #define SYSCFG_EXTICR1         (*((uint32 *)( _SYSCFG_BASE_ADDRESS  +	0x08  )))     
 #define SYSCFG_EXTICR2         (*((uint32 *)( _SYSCFG_BASE_ADDRESS  +	0x0C  )))
 #define SYSCFG_EXTICR3         (*((uint32 *)( _SYSCFG_BASE_ADDRESS  +	0x10  )))
 #define SYSCFG_EXTICR4         (*((uint32 *)( _SYSCFG_BASE_ADDRESS  +	0x14  )))
 
 
 #endif