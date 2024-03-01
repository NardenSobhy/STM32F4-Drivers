 /******************************************************************************
 *
 * Module: GPIO
 *
 * File Name: GPIO_private.h
 *
 * CREATE: 26/11/2023
 *
 * Author: Narden Sobhy
 *
 *******************************************************************************/
 
 /*=====================================================================================
===================    guard of file will call on time in .c	    ===================
=======================================================================================*/ 

 #ifndef GPIO_PRIVATE_H
 #define GPIO_PRIVATE_H
  
 /*=================================================================================
	-----> Macros
			*  Base_Address GPIOx				
 =================================================================================*/
 #define  GPIOA_BASE_ADDRESS         0x40020000 
 #define  GPIOB_BASE_ADDRESS         0x40020400
 #define  GPIOC_BASE_ADDRESS         0x40020800 
 #define  GPIOD_BASE_ADDRESS 		 0x40020C00
 #define  GPIOE_BASE_ADDRESS 		 0x40021000
 #define  GPIOH_BASE_ADDRESS 		 0x40021C00
  
 /*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_A		
 ===================================================================================*/
 #define GPIOA_MODER            (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x00)))
 #define GPIOA_OTYPER           (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x04)))
 #define GPIOA_OSPEEDR          (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x08)))
 #define GPIOA_PUPDR            (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x0C)))
 #define GPIOA_IDR              (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x10)))
 #define GPIOA_ODR              (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x14)))
 #define GPIOA_BSRR             (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x18)))
 #define GPIOA_LCKR             (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x1C)))
 #define GPIOA_AFRL             (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x20)))
 #define GPIOA_AFRH             (*((volatile uint32 *)(GPIOA_BASE_ADDRESS+0x24)))
  
 /*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_B		
 ===================================================================================*/
 #define GPIOB_MODER            (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x00)))
 #define GPIOB_OTYPER           (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x04)))
 #define GPIOB_OSPEEDR          (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x08)))
 #define GPIOB_PUPDR            (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x0C)))
 #define GPIOB_IDR              (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x10)))
 #define GPIOB_ODR              (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x14)))
 #define GPIOB_BSRR             (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x18)))
 #define GPIOB_LCKR             (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x1C)))
 #define GPIOB_AFRL             (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x20)))
 #define GPIOB_AFRH             (*((volatile uint32 *)(GPIOB_BASE_ADDRESS+0x24)))
 
 /*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_C		
 ===================================================================================*/
 #define GPIOC_MODER            (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x00)))
 #define GPIOC_OTYPER           (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x04)))
 #define GPIOC_OSPEEDR          (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x08)))
 #define GPIOC_PUPDR            (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x0C)))
 #define GPIOC_IDR              (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x10)))
 #define GPIOC_ODR              (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x14)))
 #define GPIOC_BSRR             (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x18)))
 #define GPIOC_LCKR             (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x1C)))
 #define GPIOC_AFRL             (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x20)))
 #define GPIOC_AFRH             (*((volatile uint32 *)(GPIOC_BASE_ADDRESS+0x24)))
 
 /*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_D		
 ===================================================================================*/
 #define GPIOD_MODER            (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x00)))
 #define GPIOD_OTYPER           (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x04)))
 #define GPIOD_OSPEEDR          (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x08)))
 #define GPIOD_PUPDR            (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x0C)))
 #define GPIOD_IDR              (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x10)))
 #define GPIOD_ODR              (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x14)))
 #define GPIOD_BSRR             (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x18)))
 #define GPIOD_LCKR             (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x1C)))
 #define GPIOD_AFRL             (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x20)))
 #define GPIOD_AFRH             (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x24)))
 #define GPIOD_AFRH             (*((volatile uint32 *)(GPIOD_BASE_ADDRESS+0x24)))
 
  /*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_E		
 ===================================================================================*/
 #define GPIOE_MODER            (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x00)))
 #define GPIOE_OTYPER           (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x04)))
 #define GPIOE_OSPEEDR          (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x08)))
 #define GPIOE_PUPDR            (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x0C)))
 #define GPIOE_IDR              (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x10)))
 #define GPIOE_ODR              (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x14)))
 #define GPIOE_BSRR             (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x18)))
 #define GPIOE_LCKR             (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x1C)))
 #define GPIOE_AFRL             (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x20)))
 #define GPIOE_AFRH             (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x24)))
 #define GPIOE_AFRH             (*((volatile uint32 *)(GPIOE_BASE_ADDRESS+0x24)))
 
  /*=================================================================================
	-----> Macros
			  *  Register Map	 GPIO_H		
 ===================================================================================*/
 #define GPIOH_MODER            (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x00)))
 #define GPIOH_OTYPER           (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x04)))
 #define GPIOH_OSPEEDR          (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x08)))
 #define GPIOH_PUPDR            (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x0C)))
 #define GPIOH_IDR              (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x10)))
 #define GPIOH_ODR              (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x14)))
 #define GPIOH_BSRR             (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x18)))
 #define GPIOH_LCKR             (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x1C)))
 #define GPIOH_AFRL             (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x20)))
 #define GPIOH_AFRH             (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x24)))
 #define GPIOH_AFRH             (*((volatile uint32 *)(GPIOH_BASE_ADDRESS+0x24)))
 
 
 /*================================================================
	-)Struct : General Purpose I/O				
 =================================================================*/
 typedef struct{
	volatile uint32 MODER  ;  /*!< GPIO port mode register,               Address offset: 0x00      */
	volatile uint32 OTYPER ;  /*!< GPIO port output type register,        Address offset: 0x04      */
	volatile uint32 OSPEEDR;  /*!< GPIO port output speed register,       Address offset: 0x08      */
	volatile uint32 PUPDR  ;  /*!< GPIO port pull-up/pull-down register,  Address offset: 0x0C      */
	volatile uint32 IDR    ;  /*!< GPIO port input data register,         Address offset: 0x10      */
	volatile uint32 ODR    ;  /*!< GPIO port output data register,        Address offset: 0x14      */
	volatile uint32 BSRR   ;  /*!< GPIO port bit set/reset register,      Address offset: 0x18      */
	volatile uint32 LCKR   ;  /*!< GPIO port configuration lock register, Address offset: 0x1C      */
	volatile uint32 AFRL   ;  /*!< GPIO alternate function registers,     Address offset: 0x20-0x24 */
	volatile uint32 AFRH   ;
}GPIOx_t;
 
 /*================================================================
	-)Struct Macros :
			*  Base_Address GPIOA 				
 =================================================================*/
 #define MGPIOA        ((GPIOx_t *) (GPIOA_BASE_ADDRESS ))

/*====================================================== ==========
	-)Struct Macros :
			*  Base_Address GPIOB				
 =================================================================*/       
 #define MGPIOB        ((GPIOx_t *) (GPIOB_BASE_ADDRESS ))

 /*================================================================
	-)Struct Macros :
			*  Base_Address GPIOC 				
 =================================================================*/  
 #define MGPIOC        ((GPIOx_t *) (GPIOC_BASE_ADDRESS ))

 /*================================================================
	-)Struct Macros :
			*  Base_Address GPIOD				
 =================================================================*/  
 #define MGPIOD        ((GPIOx_t *) (GPIOD_BASE_ADDRESS ))

 /*================================================================
	-)Struct Macros :
			*  Base_Address GPIOE				
 =================================================================*/  
 #define MGPIOE        ((GPIOx_t *) (GPIOE_BASE_ADDRESS ))

 /*================================================================
	-)Struct Macros :
			*  Base_Address GPIOH				
 =================================================================*/  
 #define MGPIOH        ((GPIOx_t *) (GPIOH_BASE_ADDRESS ))


 #define _LUCKED_PIN 16U


 #endif