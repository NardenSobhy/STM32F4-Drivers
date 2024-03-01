/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_interface.h
 *
 * CREATE: 26/11/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
/*===================================================================================
===============     guard of file will call on time in .c		   ==================
=====================================================================================*/
 
 #ifndef GPIO_INTERFACE_H
 #define GPIO_INTERFACE_H

 /*===========  Include  ===========*/
  
 #include "STD_TYPES.h"
 #include "GPIO_private.h"
 #include "GPIO_config.h"

 
 /*======== Macros Of Port ========*/
 #define _GPIOA_PORT   		      (0U)            /*!< GPIO (A) PORT  */
 #define _GPIOB_PORT   		      (1U)            /*!< GPIO (B) PORT  */
 #define _GPIOC_PORT   		      (2U)            /*!< GPIO (C) PORT  */
 #define _GPIOD_PORT   		      (3U)            /*!< GPIO (D) PORT  */
 #define _GPIOE_PORT   		      (4U)            /*!< GPIO (E) PORT  */
 #define _GPIOH_PORT   		      (5U)            /*!< GPIO (H) PORT  */
 
 /*======== Macros Of Pins ========*/
 #define GPIO_PIN_0            		0U  		   //((u16)0x0001)   /*!< Pin 0 selected    */
 #define GPIO_PIN_1            		1U  		   //((u16)0x0002)   /*!< Pin 1 selected    */
 #define GPIO_PIN_2            		2U  		   //((u16)0x0004)   /*!< Pin 2 selected    */
 #define GPIO_PIN_3            		3U  		   //((u16)0x0008)   /*!< Pin 3 selected    */
 #define GPIO_PIN_4            		4U  		   //((u16)0x0010)   /*!< Pin 4 selected    */
 #define GPIO_PIN_5            		5U  		   //((u16)0x0020)   /*!< Pin 5 selected    */
 #define GPIO_PIN_6            		6U  		   //((u16)0x0040)   /*!< Pin 6 selected    */
 #define GPIO_PIN_7            		7U  		   //((u16)0x0080)   /*!< Pin 7 selected    */
 #define GPIO_PIN_8            		8U  		   //((u16)0x0100)   /*!< Pin 8 selected    */
 #define GPIO_PIN_9            		9U  		   //((u16)0x0200)   /*!< Pin 9 selected    */
 #define GPIO_PIN_10           		10U 		   //((u16)0x0400)   /*!< Pin 10 selected   */
 #define GPIO_PIN_11           		11U 		   //((u16)0x0800)   /*!< Pin 11 selected   */
 #define GPIO_PIN_12           		12U 		   //((u16)0x1000)   /*!< Pin 12 selected   */
 #define GPIO_PIN_13           		13U 		   //((u16)0x2000)   /*!< Pin 13 selected   */
 #define GPIO_PIN_14           		14U 		   //((u16)0x4000)   /*!< Pin 14 selected   */
 #define GPIO_PIN_15           		15U 		   //((u16)0x8000)   /*!< Pin 15 selected   */
 #define GPIO_PIN_All              	((u16)0xFFFF)   /*!< All pins selected */
 
 /*======== Macros Of Mode ========*/
 #define _MODE_INPUT      	      (0b00)          /*!< MODE ---> INPUT     */
 #define _MODE_OUTPUT     	      (0b01)          /*!< MODE ---> OUTPUT    */
 #define _MODE_ALTF       	      (0b10)          /*!< MODE ---> ALTF      */
 #define _MODE_ANALOG     	      (0b11)          /*!< MODE ---> ANALOG    */
 
 /*======== Macros Of Output Type ========*/
 #define _OUTPUT_TYPE_PUSH_PULL    (0U)           /*!< OUTPUT TYPE ---> PUSH PULL   */  
 #define _OUTPUT_TYPE_OPEN_DRAIN   (1U)           /*!< OUTPUT TYPE ---> OPEN DRAIN  */
 
 /*======== Macros Of Speed ========*/
 #define _OUTPUT_SPEED_LOW         (0x00000000U)  /*!< IO works at 2 MHz, please refer to the product datasheet */
 #define _OUTPUT_SPEED_MEDUIM      (0x00000001U)  /*!< range 12,5 MHz to 50 MHz, please refer to the product datasheet */
 #define _OUTPUT_SPEED_HIGH        (0x00000002U)  /*!< range 25 MHz to 100 MHz, please refer to the product datasheet  */
 #define _OUTPUT_SPEED_VERY_HIGH   (0x00000003U)  /*!< range 50 MHz to 200 MHz, please refer to the product datasheet  */
 
 /*======== Macros Of PULL  ========*/
 #define _PULL_OFF                 (0x00000000U)   /*!< No Pull-up or Pull-down activation  */
 #define _PULL_UP                  (0x00000001U)   /*!< Pull-up activation                  */
 #define _PULL_DOWN                (0x00000002U)   /*!< Pull-down activation                */

 /*======== Macros Write Data  ========*/
 #define _HIGH                     (0U)
 #define _LOW	                   (1U)
 
 /*======== Macros ALTF  ========*/
 #define _ALTFN_0                  (0b0000)      /*!< ALTF  --> 0  */
 #define _ALTFN_1                  (0b0001)      /*!< ALTF  --> 1  */
 #define _ALTFN_2                  (0b0010)      /*!< ALTF  --> 2  */
 #define _ALTFN_3                  (0b0011)      /*!< ALTF  --> 3  */
 #define _ALTFN_4                  (0b0100)      /*!< ALTF  --> 4  */
 #define _ALTFN_5                  (0b0101)      /*!< ALTF  --> 5  */
 #define _ALTFN_6                  (0b0110)      /*!< ALTF  --> 6  */
 #define _ALTFN_7                  (0b0111)      /*!< ALTF  --> 7  */
 #define _ALTFN_8                  (0b1000)      /*!< ALTF  --> 8  */
 #define _ALTFN_9                  (0b1001)      /*!< ALTF  --> 9  */
 #define _ALTFN_10                 (0b1010)      /*!< ALTF  --> 10 */
 #define _ALTFN_11                 (0b1011)      /*!< ALTF  --> 11 */
 #define _ALTFN_12                 (0b1100)      /*!< ALTF  --> 12 */
 #define _ALTFN_13                 (0b1101)      /*!< ALTF  --> 13 */
 #define _ALTFN_14                 (0b1110)      /*!< ALTF  --> 14 */
 #define _ALTFN_15                 (0b1111)      /*!< ALTF  --> 15 */

 /*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/
 
/*	Function Set The Mode Of Pin Mode Take 2Bits	
*			1- _MODE_INPUT 
*			2- _MODE_OUTPUT
*			3- _MODE_ALTF  
*			4- _MODE_ANALOG
*/
 void MGPIO_vSetPinMode(uint8 Copy_PortName, uint8 Copy_PinNum, uint8 Copy_Mode);
 
 
/*	Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1) :
*		- _OUTPUT_TYPE_PUSH_PULL
*		- _OUTPUT_TYPE_OPEN_DRAIN	
*/
 void MGPIO_vSetPinOutputType(uint8 Copy_PortName, uint8 Copy_PinNum, uint8 Copy_OutputType);
  
  
/* Function Set The Speed (LOW , Meduim , High ,VeryHaigh):		
*		- _OUTPUT_SPEED_LOW      
*		- _OUTPUT_SPEED_MEDUIM   
*		- _OUTPUT_SPEED_HIGH     
*		- _OUTPUT_SPEED_VERY_HIGH	
*/
 void MGPIO_vSetPinOutSpeed(uint8 Copy_PortName, uint8 Copy_PinNum, uint8 Copy_OutSpeed); 
   

/*		
 * Function To Read Data From IDR register
 */   
 uint8 MGPIO_u8ReadData(uint8 Copy_PortName ,uint8 Copy_PinNum);
 
 
/*		
* Function To Write Data At ODR	Value :
*		 - _HIGH  
*		 - _LOW	
*/
 void MGPIO_vWriteData(uint8 Copy_PortName ,uint8 Copy_PinNum ,uint8 Copy_State);
 
 
 /*
* Function to Lock pin :
*		    1)Set Pin 
*			2)Set Pin 16
*			3)Wait until bit 16 = high
*/
 void MGPIO_vPinLock(uint8 Copy_PortName ,uint8 Copy_PinNum);
 

/*		
* Function To Set ALTF
*/ 
 void MGPIO_vSetPinAltFn(uint8 Copy_PortName ,uint8 Copy_PinNum, uint8 Copy_AltFn );
 
 /*		
* Function To Send One Byte
*/
 void MGPIO_vPortOutputOneByte(uint8 Copy_PortName, uint8 Copy_Data, uint8 Copy_StartBit);
 
 
 #endif