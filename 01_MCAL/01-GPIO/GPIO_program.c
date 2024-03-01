/******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_program.c
 *
 * CREATE: 26/11/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
/*===========   INCLUDE LIB   ===========*/
	#include "STD_TYPES.h"
	#include "COMMON_MACROS.h"
  
/*===========  INCLUDE MCAL  ===========*/
	#include "GPIO_private.h"
	#include "GPIO_interface.h"
	#include "GPIO_config.h"
	
/*******************************************************************************
 *                      Functions Definitions                                  *
*******************************************************************************/

/*	Function Set The Mode Of Pin Mode Take 2Bits	
*			1- _MODE_INPUT 
*			2- _MODE_OUTPUT
*			3- _MODE_ALTF  
*			4- _MODE_ANALOG
*/
 void MGPIO_vSetPinMode(uint8 Copy_PortName, uint8 Copy_PinNum, uint8 Copy_Mode)
 {
	switch(Copy_PortName)
	{
		case _GPIOA_PORT :  MGPIOA->MODER  |= (uint32) ( Copy_Mode << ( 2U* Copy_PinNum ));  break;
		case _GPIOB_PORT :  MGPIOB->MODER  |= (uint32) ( Copy_Mode << ( 2U* Copy_PinNum ));  break;
		case _GPIOC_PORT :  MGPIOC->MODER  |= (uint32) ( Copy_Mode << ( 2U* Copy_PinNum ));  break;
		case _GPIOD_PORT :  MGPIOD->MODER  |= (uint32) ( Copy_Mode << ( 2U* Copy_PinNum ));  break;
		case _GPIOE_PORT :  MGPIOE->MODER  |= (uint32) ( Copy_Mode << ( 2U* Copy_PinNum ));  break;
		case _GPIOH_PORT :  MGPIOH->MODER  |= (uint32) ( Copy_Mode << ( 2U* Copy_PinNum ));  break;
		default: /*ERROR*/ break;
	}
 }

/*	Function Set The Type Of OutPut (OpenDrain = 0 , PushPull = 1) :
*		- _OUTPUT_TYPE_PUSH_PULL
*		- _OUTPUT_TYPE_OPEN_DRAIN	
*/
 void MGPIO_vSetPinOutputType(uint8 Copy_PortName, uint8 Copy_PinNum, uint8 Copy_OutputType)
 {
	switch(Copy_PortName)
	{
		case _GPIOA_PORT :  MGPIOA->OTYPER  |= (uint32) ( Copy_OutputType << ( Copy_PinNum ));  break;
		case _GPIOB_PORT :  MGPIOB->OTYPER  |= (uint32) ( Copy_OutputType << ( Copy_PinNum ));  break;
		case _GPIOC_PORT :  MGPIOC->OTYPER  |= (uint32) ( Copy_OutputType << ( Copy_PinNum ));  break;
		case _GPIOD_PORT :  MGPIOD->OTYPER  |= (uint32) ( Copy_OutputType << ( Copy_PinNum ));  break;
		case _GPIOE_PORT :  MGPIOE->OTYPER  |= (uint32) ( Copy_OutputType << ( Copy_PinNum ));  break;
		case _GPIOH_PORT :  MGPIOH->OTYPER  |= (uint32) ( Copy_OutputType << ( Copy_PinNum ));  break;
		default: /*ERROR*/ break;
	} 
  }
  
/* Function Set The Speed (LOW , Meduim , High ,VeryHaigh):		
*		- _OUTPUT_SPEED_LOW      
*		- _OUTPUT_SPEED_MEDUIM   
*		- _OUTPUT_SPEED_HIGH     
*		- _OUTPUT_SPEED_VERY_HIGH	
*/
 void MGPIO_vSetPinOutSpeed(uint8 Copy_PortName, uint8 Copy_PinNum, uint8 Copy_OutSpeed)
 {
	switch(Copy_PortName)
	{
		case _GPIOA_PORT :  MGPIOA->OSPEEDR  |= (uint32) ( Copy_OutSpeed << ( 2U* Copy_PinNum ));  break;
		case _GPIOB_PORT :  MGPIOB->OSPEEDR  |= (uint32) ( Copy_OutSpeed << ( 2U* Copy_PinNum ));  break;
		case _GPIOC_PORT :  MGPIOC->OSPEEDR  |= (uint32) ( Copy_OutSpeed << ( 2U* Copy_PinNum ));  break;
		case _GPIOD_PORT :  MGPIOD->OSPEEDR  |= (uint32) ( Copy_OutSpeed << ( 2U* Copy_PinNum ));  break;
		case _GPIOE_PORT :  MGPIOE->OSPEEDR  |= (uint32) ( Copy_OutSpeed << ( 2U* Copy_PinNum ));  break;
		case _GPIOH_PORT :  MGPIOH->OSPEEDR  |= (uint32) ( Copy_OutSpeed << ( 2U* Copy_PinNum ));  break;
		default: /*ERROR*/ break;
	}
 } 
 
/*	Function Set The PULL :			
*	    - _PULL_OFF
*	    - _PULL_UP
*	    - _PULL_DOWN
*/
 void MGPIO_vSetPullType(uint8 Copy_PortName, uint8 Copy_PinNum, uint8 Copy_PullType)
  {
	switch(Copy_PortName)
	{
		case _GPIOA_PORT :  MGPIOA->PUPDR  |= (uint32) ( Copy_PullType << ( 2U* Copy_PinNum ));  break;
		case _GPIOB_PORT :  MGPIOB->PUPDR  |= (uint32) ( Copy_PullType << ( 2U* Copy_PinNum ));  break;
		case _GPIOC_PORT :  MGPIOC->PUPDR  |= (uint32) ( Copy_PullType << ( 2U* Copy_PinNum ));  break;
		case _GPIOD_PORT :  MGPIOD->PUPDR  |= (uint32) ( Copy_PullType << ( 2U* Copy_PinNum ));  break;
		case _GPIOE_PORT :  MGPIOE->PUPDR  |= (uint32) ( Copy_PullType << ( 2U* Copy_PinNum ));  break;
		case _GPIOH_PORT :  MGPIOH->PUPDR  |= (uint32) ( Copy_PullType << ( 2U* Copy_PinNum ));  break;
		default: /*ERROR*/ break;
	}
  }
 
 /*		
 * Function To Read Data From IDR register
 */   
  uint8 MGPIO_u8ReadPin(uint8 Copy_PortName ,uint8 Copy_PinNum)
  {
	uint8 L_u8Data = 0;
	switch(Copy_PortName)
	{
		case _GPIOA_PORT :  L_u8Data = GET_BIT(MGPIOA->IDR,Copy_PinNum);  break;
		case _GPIOB_PORT :  L_u8Data = GET_BIT(MGPIOB->IDR,Copy_PinNum);  break;
		case _GPIOC_PORT :  L_u8Data = GET_BIT(MGPIOC->IDR,Copy_PinNum);  break;
		case _GPIOD_PORT :  L_u8Data = GET_BIT(MGPIOD->IDR,Copy_PinNum);  break;
		case _GPIOE_PORT :  L_u8Data = GET_BIT(MGPIOE->IDR,Copy_PinNum);  break;
		case _GPIOH_PORT :  L_u8Data = GET_BIT(MGPIOH->IDR,Copy_PinNum);  break;
		default: /*ERROR*/ break;
	}
	return L_u8Data;
  } 
  
/*		
* Function To Write Data At ODR	Value :
*		 - _HIGH  
*		 - _LOW	
*/
 
 void MGPIO_vWriteData(uint8 Copy_PortName ,uint8 Copy_PinNum ,uint8 Copy_State)
 {
	if(Copy_State == _HIGH)
	{
		switch(Copy_PortName)
		{
		case _GPIOA_PORT :  SET_BIT(MGPIOA ->ODR,Copy_PinNum); break;
		case _GPIOB_PORT :  SET_BIT(MGPIOB ->ODR,Copy_PinNum); break;
		case _GPIOC_PORT :  SET_BIT(MGPIOC ->ODR,Copy_PinNum); break;
		case _GPIOD_PORT :  SET_BIT(MGPIOD ->ODR,Copy_PinNum); break;
		case _GPIOE_PORT :  SET_BIT(MGPIOE ->ODR,Copy_PinNum); break;
		case _GPIOH_PORT :  SET_BIT(MGPIOH ->ODR,Copy_PinNum); break;
		default : /*ERROR*/ break ;
		}	
	}
	else{
		switch(Copy_PortName)
		{
		case _GPIOA_PORT :  CLEAR_BIT(MGPIOA ->ODR,Copy_PinNum); break;
		case _GPIOB_PORT :  CLEAR_BIT(MGPIOB ->ODR,Copy_PinNum); break;
		case _GPIOC_PORT :  CLEAR_BIT(MGPIOC ->ODR,Copy_PinNum); break;
		case _GPIOD_PORT :  CLEAR_BIT(MGPIOD ->ODR,Copy_PinNum); break;
		case _GPIOE_PORT :  CLEAR_BIT(MGPIOE ->ODR,Copy_PinNum); break;
		case _GPIOH_PORT :  CLEAR_BIT(MGPIOH ->ODR,Copy_PinNum); break;
		default : /*ERROR*/ break ;
		}
	}
 }
 
 /*
- Function to Lock pin :
		    1)Set Pin 
			2)Set Pin 16
			3)Wait until bit 16 = high
*/
 
 void MGPIO_vPinLock(uint8 Copy_PortName ,uint8 Copy_PinNum)
 {
	switch(Copy_PortName)	
    {
		case _GPIOA_PORT  : 
			SET_BIT(MGPIOA->LCKR,Copy_PinNum );
			SET_BIT(MGPIOA->LCKR,_LUCKED_PIN );
			while(!(GET_BIT(MGPIOA->LCKR,_LUCKED_PIN)));
		break ; 
	    /*************************************************/
		case _GPIOB_PORT  : 
			SET_BIT(MGPIOB->LCKR,Copy_PinNum );
			SET_BIT(MGPIOB->LCKR,_LUCKED_PIN );
			while(!(GET_BIT(MGPIOB->LCKR,_LUCKED_PIN)));
		break ; 
	    /*************************************************/
	    case _GPIOC_PORT  : 
			SET_BIT(MGPIOC->LCKR,Copy_PinNum );
			SET_BIT(MGPIOC->LCKR,_LUCKED_PIN );
			while(!(GET_BIT(MGPIOC->LCKR,_LUCKED_PIN)));
		break ; 
	    /*************************************************/
		case _GPIOD_PORT  : 
			SET_BIT(MGPIOD->LCKR,Copy_PinNum );
			SET_BIT(MGPIOD->LCKR,_LUCKED_PIN );
			while(!(GET_BIT(MGPIOD->LCKR,_LUCKED_PIN)));
		break ;
		/*************************************************/	 
		case _GPIOE_PORT  : 
			SET_BIT(MGPIOE->LCKR,Copy_PinNum );
			SET_BIT(MGPIOE->LCKR,_LUCKED_PIN );
			while(!(GET_BIT(MGPIOE->LCKR,_LUCKED_PIN)));
		break ;
		/*************************************************/	
		case _GPIOH_PORT  : 
			SET_BIT(MGPIOH->LCKR,Copy_PinNum );
			SET_BIT(MGPIOH->LCKR,_LUCKED_PIN );
			while(!(GET_BIT(MGPIOH->LCKR,_LUCKED_PIN)));
		break ;
		/*************************************************/	
    }
 } 
	 

/*		
* Function To Set ALTF
*/ 
 void MGPIO_vSetPinAltFn(uint8 Copy_PortName ,uint8 Copy_PinNum, uint8 Copy_AltFn )
 {
	if(Copy_PinNum <= 7U)
	{
		switch(Copy_PortName)
		{
			case _GPIOA_PORT  : MGPIOA->AFRL |=(uint32)(Copy_AltFn <<(4U* Copy_PinNum)); break ;
			case _GPIOB_PORT  : MGPIOB->AFRL |=(uint32)(Copy_AltFn <<(4U* Copy_PinNum)); break ;
			case _GPIOC_PORT  : MGPIOC->AFRL |=(uint32)(Copy_AltFn <<(4U* Copy_PinNum)); break ;
			case _GPIOD_PORT  : MGPIOD->AFRL |=(uint32)(Copy_AltFn <<(4U* Copy_PinNum)); break ;
			case _GPIOE_PORT  : MGPIOE->AFRL |=(uint32)(Copy_AltFn <<(4U* Copy_PinNum)); break ;
			case _GPIOH_PORT  : MGPIOH->AFRL |=(uint32)(Copy_AltFn <<(4U* Copy_PinNum)); break ;
			default :/*ERROR*/ break ;	
		}
	}
	// 8 : 15
	// i need 8 = 0 & 15 = 7
	else
	{
		switch(Copy_PortName)
		{
			 case _GPIOA_PORT  : MGPIOA->AFRH |=(uint32)(Copy_AltFn <<(4U* (Copy_PinNum % 8U ))); break ;
			 case _GPIOB_PORT  : MGPIOB->AFRH |=(uint32)(Copy_AltFn <<(4U* (Copy_PinNum % 8U ))); break ;
			 case _GPIOC_PORT  : MGPIOC->AFRH |=(uint32)(Copy_AltFn <<(4U* (Copy_PinNum % 8U ))); break ;
			 case _GPIOD_PORT  : MGPIOD->AFRH |=(uint32)(Copy_AltFn <<(4U* (Copy_PinNum % 8U ))); break ;
			 case _GPIOE_PORT  : MGPIOE->AFRH |=(uint32)(Copy_AltFn <<(4U* (Copy_PinNum % 8U ))); break ;
			 case _GPIOH_PORT  : MGPIOH->AFRH |=(uint32)(Copy_AltFn <<(4U* (Copy_PinNum % 8U ))); break ;
			 default :/*ERROR*/ break ;
		}	
	}
 }
 

/*		
* Function To Send One Byte
*/
 void MGPIO_vPortOutputOneByte(uint8 Copy_PortName, uint8 Copy_Data, uint8 Copy_StartBit)
 {
	switch(Copy_PortName){
		case _GPIOA_PORT :
			MGPIOA->ODR = (MGPIOA->ODR & ~(0xff << (Copy_StartBit ))) | (Copy_Data << (Copy_StartBit));
			break;
		case _GPIOB_PORT :
			MGPIOB->ODR = (MGPIOB->ODR & ~(0xff << (Copy_StartBit ))) | (Copy_Data << (Copy_StartBit));
			break;
		case _GPIOC_PORT :
			MGPIOC->ODR = (MGPIOC->ODR & ~(0xff << (Copy_StartBit ))) | (Copy_Data << (Copy_StartBit));
			break;
		case _GPIOD_PORT :
			MGPIOD->ODR = (MGPIOD->ODR & ~(0xff << (Copy_StartBit ))) | (Copy_Data << (Copy_StartBit));
			break;
		case _GPIOE_PORT :
			MGPIOE->ODR = (MGPIOE->ODR & ~(0xff << (Copy_StartBit ))) | (Copy_Data << (Copy_StartBit));
			break;
		case _GPIOH_PORT :
			MGPIOH->ODR = (MGPIOH->ODR & ~(0xff << (Copy_StartBit ))) | (Copy_Data << (Copy_StartBit));
			break;
	}
}