/******************************************************************************
 *
 * Module: DELAY
 *
 * File Name: DELAY_interface.h
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 
 /*========================================================================================
========================   guard of file will call on time in .c  ========================
========================================================================================*/ 
#ifndef DELAY_INTERFACE_H
#define DELAY_INTERFACE_H
	 
#include "STD_TYPES.h"


/*========================================================================================
 *                      Functions Prototypes                                   *
========================================================================================*/


  /* =============  Function To Delay By Milliseconds ( 16MHz CPU CLK )   ============= */
  extern void Delay_voidMsIn16MHz(uint16 copy_u16CountNum);

 /* =============  Function To Delay By Microseconds ( 16MHz CPU CLK )   ============= */
  extern void Delay_voidUsIn16MHzint (uint16 copy_u16CountNum);




#endif //DELAY_INTERFACE_H