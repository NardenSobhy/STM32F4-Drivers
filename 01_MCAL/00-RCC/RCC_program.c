/******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_program.c
 *
 * CREATE: 27/10/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 
/*===========   INCLUDE LIB   ===========*/
		#include "STD_TYPES.h"
		#include "COMMON_MACROS.h"
  
/*===========  INCLUDE MCAL  ===========*/
		#include "RCC_private.h"
		#include "RCC_interface.h"
		#include "RCC_config.h"
		

/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/
 
 /* -Function To Enable Prephiral
 *		 -BusName:The name of the bus of the prephiral (AHB1 , AHB2 , APB1 , APB2)
 *		 -COPY_u8PerNum: The Number of the Prephiral
 */

 void MRCC_vEnableClock(BusName_t BusName, uint8 Copy_u8PerNum)
{
	switch(BusName)
	{
		case AHB1_BUS: 	SET_BIT(RCC_AHB1ENR , Copy_u8PerNum);	break;
		case AHB2_BUS: 	SET_BIT(RCC_AHB2ENR , Copy_u8PerNum);	break;
		case APB1_BUS: 	SET_BIT(RCC_APB1ENR , Copy_u8PerNum);	break;
		case APB2_BUS: 	SET_BIT(RCC_APB2ENR , Copy_u8PerNum);	break;
		default: 		/*ERROR*/								break;
	}
}

 /* -Function To Disable Prephiral
 *		 -BusName: The name of the bus of the prephiral (AHB1 , AHB2 , APB1 , APB2)
 *		 -COPY_u8PeriNum: The Number of the Prephiral
 */
 void MRCC_vDisableClock(BusName_t BusName, uint8 Copy_u8PerNum)
 {
	switch(BusName)
	{
		case AHB1_BUS: 	CLEAR_BIT(RCC_AHB1ENR , Copy_u8PerNum);	break;
		case AHB2_BUS: 	CLEAR_BIT(RCC_AHB2ENR , Copy_u8PerNum);	break;
		case APB1_BUS: 	CLEAR_BIT(RCC_APB1ENR , Copy_u8PerNum);	break;
		case APB2_BUS: 	CLEAR_BIT(RCC_APB2ENR , Copy_u8PerNum);	break;
		default: 	/*ERROR*/									break;
	}
}
 
 /*
 * Function To Enable Clock Security System
 */
 void MRCC_vEnableClockSecuritySystem(void)
{
	SET_BIT(RCC_CR,CSSON);
}

/*
* Function To Disable Security System
*/
void MRCC_vDisableClockSecuritySystem(void)
{
	CLEAR_BIT(RCC_CR,CSSON);
}



/* About The Function :
	
				- CLK		: HSE | HSI |PLL	
				- PLLSrc	:PLL_HSE | PLL_HSI
				- HSESrc    :HSE_Crystal ,HSE_RC 
 */

void MRCC_vInitSystemClock(void)
{
	/********** HSI **********/
#if CLKSRC == HSI
	/*Enable HSI*/
	SET_BIT(MRCC->CR , 0U);
	/*INPUT SYSTEM CLOCK -> HSI*/
	CLEAR_BIT(MRCC->CFGR , 0U);
	CLEAR_BIT(MRCC->CFGR , 1U);

	/********** HSE **********/
#elif CLKSRC == HSE	
	#if HSE_SRC == _HSE_CRYSTAL
		/*Enable HSE*/
		SET_BIT(MRCC->CR , 16U);			
		/*DISABLE BYPASS*/
		CLEAR_BIT(MRCC->CR , 18U);
		/*INPUT SYSTEM CLOCK -> HSE*/
		SET_BIT(MRCC->CFGR , 0U);
		CLEAR_BIT(MRCC->CFGR , 1U);
	#elif HSE_SRC == _HSE_RC
		/*Enable HSE*/
		SET_BIT(MRCC->CR , 16U);			
		/*ENABLE BYPASS*/
		SET_BIT(MRCC->CR , 18U);
		/*INPUT SYSTEM CLOCK -> HSE*/
		SET_BIT(MRCC->CFGR , 0U);
		CLEAR_BIT(MRCC->CFGR , 1U);
	#else
		/*Error*/
	#endif
	
	/********** PLL **********/
#elif CLKSRC == PLL
	#if PLL_SRC == _HSE_PLL
		/*Enable HSE*/
		SET_BIT(MRCC->CR , 16U);
		/*Enable PLL*/
		SET_BIT(MRCC->CR , 24U);
		/*HSE oscillator clock selected as PLL*/
		SET_BIT(MRCC->PLLCFGR , 22U);
		/*INPUT SYSTEM CLOCK -> PLL*/
		CLEAR_BIT(MRCC->CFGR , 0U);
		SET_BIT(MRCC->CFGR , 1U);
	
	#elif PLL_SRC == _HSI_PLL
		/*Enable HSI*/
		SET_BIT(MRCC->CR , 0U);
		/*Enable PLL*/
		SET_BIT(MRCC->CR , 24U);
		/*HSI clock selected as PLL*/
		CLEAR_BIT_BIT(MRCC->PLLCFGR , 22U);
		/*INPUT SYSTEM CLOCK -> PLL*/
		CLEAR_BIT(MRCC->CFGR , 0U);
		SET_BIT(MRCC->CFGR , 1U);
	
	#else
		/*Error*/
	#endif	
	/******************************/
	
#else 
	/*Error*/
#endif // The end of big IF
}

/* -Function To Set System CLK From Enum Type Send :
		* ClkSrcName_t 		: RCC_HSE  RCC_HSI	RCC_PLL	
		* HSESrcName_t 		: Crystal CLK From (HSE_Crystal , HSE_RC )
		* AHBPreName_t    : AHB  Prescaller ( 1 : 512 )
		* APB1PreName_t   : APB1 Prescaller ( 1 : 16  )  
		* APB2PreName_t   : APB2_Prescaller ( 1 : 16  ) 
		*( M N P Q )      : By #define .															
*/

void MRCC_vInitClock(CLKSrcName_t Copy_tCLKSrc , HSESrc_t Copy_tHSESrc , PLLSrc_t Copy_tPLLSrc)
{
	switch(Copy_tCLKSrc){
		case HSE:
		switch(Copy_tHSESrc){
			case _HSE_CRYSTAL:
				/*Enable HSE*/
				SET_BIT(RCC_CR,16U);			
				/*DISABLE BYPASS*/
				CLEAR_BIT(RCC_CR,18U);
				/*INPUT SYSTEM CLOCK*/
				SET_BIT(RCC_CFGR , 0U);
				CLEAR_BIT(RCC_CFGR , 1U);
			break;
			/*********************/
			case _HSE_RC:
				/*Enable HSE*/
				SET_BIT(RCC_CR,16U);			
				/*DISABLE BYPASS*/
				SET_BIT(RCC_CR,18U);
				/*INPUT SYSTEM CLOCK*/
				SET_BIT(RCC_CFGR , 0U);
				CLEAR_BIT(RCC_CFGR , 1U);
			break;
			/*********************/
			default:  break;
			
		}
			
		break;
		/*********************/
		case HSI:
			/*Enable HSI*/
			SET_BIT(RCC_CR , 0U);
			/*INPUT SYSTEM CLOCK*/
			CLEAR_BIT(RCC_CFGR , 0U);
			CLEAR_BIT(RCC_CFGR , 1U);
		break;
		/*********************/
		case PLL:
		switch(Copy_tPLLSrc){
			case _HSE_PLL:
				/*Enable HSE*/
				SET_BIT(RCC_CR,16U);
				/*Enable PLL*/
				SET_BIT(RCC_CR,24U);
				/*HSE oscillator clock selected as PLL*/
				SET_BIT(RCC_PLLCFGR, 22U);
				/*INPUT SYSTEM CLOCK*/
				CLEAR_BIT(RCC_CFGR , 0U);
				SET_BIT(RCC_CFGR , 1U);
			break;
			/*********************/
			case _HSI_PLL:
				/*Enable HSI*/
				SET_BIT(RCC_CR , 0U);
				/*Enable PLL*/
				SET_BIT(RCC_CR,24U);
				/*HSI clock selected as PLL*/
				CLEAR_BIT_BIT(RCC_PLLCFGR, 22U);
				/*INPUT SYSTEM CLOCK*/
				CLEAR_BIT(RCC_CFGR , 0U);
				SET_BIT(RCC_CFGR , 1U);
			break;
			/*********************/
			default:   break;
		break;
		}
		
	}
}
