/******************************************************************************
 *
 * Module: EXTI
 *
 * File Name: EXTI_interface.h
 *
 * CREATE: 20/2/2024
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 #ifndef EXTI_INTERFACE_H
 #define EXTI_INTERFACE_H
 
 #include "STD_TYPES.h"
 #include "EXTI_private.h"
 #include "EXTI_config.h"
 
 
 
 #define _EXTI_LINE_0                 0U
 #define _EXTI_LINE_1                 1U
 #define _EXTI_LINE_2                 2U
 #define _EXTI_LINE_3                 3U
 #define _EXTI_LINE_4                 4U
 #define _EXTI_LINE_5                 5U
 #define _EXTI_LINE_6                 6U
 #define _EXTI_LINE_7                 7U
 #define _EXTI_LINE_8                 8U
 #define _EXTI_LINE_9                 9U
 #define _EXTI_LINE_10                10U
 #define _EXTI_LINE_11                11U
 #define _EXTI_LINE_12                12U
 #define _EXTI_LINE_13                13U
 #define _EXTI_LINE_14                14U
 #define _EXTI_LINE_15                15U
 
 
 
 #define _RAISE_STATE                    0U 	/* Configure for rising edge trigger*/             
 #define _FALL_STATE                     1U		/* Configure for falling edge trigger*/ 
 #define _ON_CHANGE_STATE                2U		/* Configure for both rising and falling edge trigger*/ 



 #define _PORT_A_EXTI                 (0b0000) 
 #define _PORT_B_EXTI                 (0b0001) 
 #define _PORT_C_EXTI                 (0b0010)
 #define _PORT_D_EXTI                 (0b0011)
 #define _PORT_E_EXTI                 (0b0100)
 #define _PORT_H_EXTI                 (0b0111)


 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
 /** Function: Enable an external interrupt line.
 *	This function enables the specified external interrupt line, allowing it to trigger
 * 	interrupt requests.
 */
void MEXTI_vEnableLine(uint8 Copy_u8LineNUM);


 /** Function: Disable an external interrupt line.
 *	This function disables the specified external interrupt line, preventing it from
 * 	triggering interrupt requests.
 */
void MEXTI_vDisableLine(uint8 Copy_u8LineNUM, );


 /** Function: Set the trigger mode for an external interrupt line.
 *  This function configures the trigger mode for the specified external interrupt line.
 *  The trigger mode determines whether the interrupt is triggered on a rising edge,
 *  falling edge, or both edges of the corresponding signal.
 */
void MEXTI_vSetTrigger(uint8 Copy_u8LineNUM  );


 /** Function: Generate a software interrupt on an external interrupt line.
 *   This function generates a software interrupt on a specified external interrupt line.
 *   The function sets the corresponding bit in the EXTI_SWIER register to trigger a software interrupt on the line.
 */
void MEXTI_vSoftwareInterrupt(uint8 Copy_u8LineNUM );

/** Function: Configure the EXTI line to a specific GPIO port.
 * This function configures an EXTI line to use a specific GPIO port.
 * Copy_u8LineNUM is the EXTI line number to configure (e.g., MEXTI_LINE_0, MEXTI_LINE_1).
 * Copy_u8PortID is the GPIO port to associate with the EXTI line.
 * The function configures the SYSCFG_EXTICR registers based on the provided EXTI line number and GPIO port.
 */
void MEXTI_vSetEXTIConfig(uint8 Copy_u8LineNUM , uint8 Copy_u8PortID );
 
 
/** Function: Check the pending state of a specific external interrupt line
 */
uint8 MEXTI_vGetPending(uint8 Copy_u8LineNUM  );
 
  #endif