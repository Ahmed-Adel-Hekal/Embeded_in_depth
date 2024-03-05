# include "std_types.h"
# include "bit_math.h"
# include "EXTI_INTERFACE.h"
# include "EXTI_PRIVATE.h"
# include "EXTI_CONFIG.h"

static void (*gptr)(void) = NULL ; 

void EXTI0_init(){

#if MODE == LOW_LEVEL
    // LOW LEVEL 
    CLEAR_BIT(EXTI_MCUCR,0);
    CLEAR_BIT(EXTI_MCUCR,1);
#elif MODE == ANY_LOGICAL
    // anyLogical 
    SET_BIT(EXTI_MCUCR,0);
    CLEAR_BIT(EXTI_MCUCR,1);
#elif MODE == FALLING_EDGE
    // Falling Edge
    SET_BIT(EXTI_MCUCR,1);
    CLEAR_BIT(EXTI_MCUCR,0);
#elif MODE == RISING_EDGE
    // Rising Edge
    SET_BIT(EXTI_MCUCR,0);
    SET_BIT(EXTI_MCUCR,1);
#endif
SET_BIT(SREG,7);
SET_BIT(EXTI_GICR,6);

}

void Callback(void (*ptr)(void)){
	
	gptr = ptr ; 
	
}
// void __vector_1(void) __attribute__((signal)) ;
// void __vector_1(void){
// 	gptr();
//}