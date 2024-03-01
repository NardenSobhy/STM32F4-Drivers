/******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_config.h
 *
 * CREATE: 27/10/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 
 #ifndef RCC_CONFIG_H
 #define RCC_CONFIG_H
 
/* CLKSRC options:
					-HSI
					-HSE
					-PLL
*/

 #define CLKSRC HSI
 
 
/*HSE_SRC options:
					-_HSE_CRYSTAL
					-_HSE_RC
			
*/

#define HSE_SRC _HSE_CRYSTAL


/*PLL options:
				-_HSE_PLL
				-_HSI_PLL
*/

#define PLL_SRC _HSE_PLL

 
 #endif