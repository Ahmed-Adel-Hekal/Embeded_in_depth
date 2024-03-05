/*************************************************************************/
/*************** Name : Ahmed Adel Hekal *********************************/
/*************** Date : 11/8/2023        *********************************/
/*************** SWC  : DIO_Driver       *********************************/
/*************** Version : 1.0           *********************************/
/*************************************************************************/


# ifndef DIO_PRIVATE_H
# define DIO_PRIVATE_H

# define DIO_u8_INITIAL_OUTPUT    1 
# define DIO_u8_INITIAL_INPUT     0

# define DIO_u8_INITIAL_HIGH      1
# define DIO_u8_INITIAL_LOW       0
# define DIO_u8_INPUT_FLOATING    0
# define DIO_u8_INPUT_PULLUP      1 

/* Macros For Registers */

# define PORTA  (*(volatile unsigned char *)0x3B)
# define DDRA   (*(volatile unsigned char *)0x3A)
# define PINA   (*(volatile unsigned char *)0x39)

# define PORTB  (*(volatile unsigned char *)0x38)  
# define DDRB   (*(volatile unsigned char *)0x37)
# define PINB   (*(volatile unsigned char *)0x36)

# define PORTC  (*(volatile unsigned char *)0x35)
# define DDRC   (*(volatile unsigned char *)0x34)
# define PINC   (*(volatile unsigned char *)0x33)

# define PORTD  (*(volatile unsigned char *)0x32)
# define DDRD   (*(volatile unsigned char *)0x31)
# define PIND   (*(volatile unsigned char *)0x30)

/* Macros Like Function */
#define conc(a,b,c,d,e,f,g,h)    conc_help(a,b,c,d,e,f,g,h)
#define conc_help(a,b,c,d,e,f,g,h)   0b##a##b##c##d##e##f##g##h


#endif