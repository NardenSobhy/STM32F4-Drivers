 /******************************************************************************
 *
 * Module: RCC
 *
 * File Name: RCC_private.h
 *
 * CREATE: 27/10/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 #ifndef RCC_PRIVATE_H
 #define RCC_PRIVATE_H
 
 
 /*
--------------> MACROS
*Base Address is (RCC) 0x40023800
*/

#define MRCC_BASE_ADDRESS  	0x40023800
 
 /*RCC REGISTERS
 * Register name -> Base address + Offset address
 */
 
#define RCC_CR 				(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x00) )))
#define RCC_PLLCFGR         (*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x04) )))
#define RCC_CFGR 			(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x08) )))
#define RCC_CIR 			(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x0C) )))
#define RCC_AHB1RSTR 		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x10) )))
#define RCC_AHB2RSTR 		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x14) )))
#define RCC_APB1RSTR 		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x20) )))
#define RCC_APB2RSTR 		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x24) )))
#define RCC_AHB1ENR			(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x30) )))
#define RCC_AHB2ENR			(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x34) )))
#define RCC_APB1ENR 		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x40) )))
#define RCC_APB2ENR 		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x44) )))
#define RCC_AHB1LPENR 		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x50) )))
#define RCC_AHB2LPENR		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x54) )))
#define RCC_APB1LPENR		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x60) )))
#define RCC_APB2LPENR 		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x64) )))
#define RCC_BDCR			(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x70) )))
#define RCC_CSR 			(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x74) )))
#define RCC_SSCGR 			(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x80) )))
#define RCC_PLLI2SCFGR		(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x84) )))
#define RCC_DCKCFGR			(*((volatile uint32*)( (MRCC_BASE_ADDRESS) + (0x8C) )))
 
 
 /*************************************/

#define CSSON 				19U

/*************************************/

typedef struct {
	
	volatile uint32 CR;     		  	// MRCC_BASE_ADDRESS + 0x00 
	volatile uint32 PLLCFGR;		 	// MRCC_BASE_ADDRESS + 0x04
	volatile uint32 CFGR;				// MRCC_BASE_ADDRESS + 0x08	
	volatile uint32 CIR;				// MRCC_BASE_ADDRESS + 0x0C
	volatile uint32 AHB1RSTR; 	        // MRCC_BASE_ADDRESS + 0x10
	volatile uint32 AHB2RSTR;	        // MRCC_BASE_ADDRESS + 0x14
	volatile uint32 RESERVED0[2];		// MRCC_BASE_ADDRESS + 0x18 // MRCC_BASE_ADDRESS + 0x1C
	volatile uint32 APB1RSTR;	        // MRCC_BASE_ADDRESS + 0x20
	volatile uint32 APB2RSTR; 	        // MRCC_BASE_ADDRESS + 0x24
	volatile uint32 RESERVED1[2];		// MRCC_BASE_ADDRESS + 0x28 // MRCC_BASE_ADDRESS + 0x2C
	volatile uint32 AHB1ENR;		    // MRCC_BASE_ADDRESS + 0x30
	volatile uint32 AHB2ENR;		    // MRCC_BASE_ADDRESS + 0x34
	volatile uint32 RESERVED2[2];		// MRCC_BASE_ADDRESS + 0x38 // MRCC_BASE_ADDRESS + 0x3C
	volatile uint32 APB1ENR; 	        // MRCC_BASE_ADDRESS + 0x40
	volatile uint32 APB2ENR; 	        // MRCC_BASE_ADDRESS + 0x44
	volatile uint32 RESERVED3[2];		// MRCC_BASE_ADDRESS + 0x48 // MRCC_BASE_ADDRESS + 0x4C
	volatile uint32 AHB1LPENR; 	        // MRCC_BASE_ADDRESS + 0x50
	volatile uint32 AHB2LPENR;	        // MRCC_BASE_ADDRESS + 0x54
	volatile uint32 RESERVED4[2];		// MRCC_BASE_ADDRESS + 0x58 // MRCC_BASE_ADDRESS + 0x5C
	volatile uint32 APB1LPENR;	        // MRCC_BASE_ADDRESS + 0x60
	volatile uint32 APB2LPENR; 	        // MRCC_BASE_ADDRESS + 0x64
	volatile uint32 RESERVED5[2];		// MRCC_BASE_ADDRESS + 0x68 // MRCC_BASE_ADDRESS + 0x6C
	volatile uint32 BDCR;		        // MRCC_BASE_ADDRESS + 0x70
	volatile uint32 CSR; 		        // MRCC_BASE_ADDRESS + 0x74
	volatile uint32 RESERVED6[2];		// MRCC_BASE_ADDRESS + 0x78 // MRCC_BASE_ADDRESS + 0x7C
	volatile uint32 SSCGR; 		        // MRCC_BASE_ADDRESS + 0x80
	volatile uint32 PLLI2SCFGR;	        // MRCC_BASE_ADDRESS + 0x84
	volatile uint32 RESERVED7;			// MRCC_BASE_ADDRESS + 0x88
    volatile uint32 DCKCFGR;		    // MRCC_BASE_ADDRESS + 0x8C
	
}RCC_TypeDef;

#define MRCC ((RCC_TypeDef *) MRCC_BASE_ADDRESS)


 #endif