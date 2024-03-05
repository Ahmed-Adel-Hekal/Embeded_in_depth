#ifndef EXTI_PRIVATE_H
#define EXTI_PRIVATE_H


# define  EXTI_MCUCR      *((volatile u8 *)0x55)
# define  EXTI_MCUSCR     *((volatile u8 *)0x54)
# define  EXTI_GICR       *((volatile u8 *)0x5B)
# define  EXTI_GIFR       *((volatile u8 *)0x5A)
# define  SREG            *((volatile u8 *)0x5F)

# define LOW_LEVEL      1 
# define RISING_EDGE    2
# define FALLING_EDGE   3
# define ANY_LOGICAL    4
#endif