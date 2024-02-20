// startup.c 
// Ahmed Hekal 

#include <stdint.h>

void Reset_handler();
extern main() ; 

void Default_handler(){
	Reset_handler();
}

void NMI_Handler()__attribute__((weak,alias("Default_handler")));
void Timer_Handler()__attribute__((weak,alias("Default_handler")));
void Uart_Handler()__attribute__((weak,alias("Default_handler"))) ;
extern uint32_t _STACK_TOP ;
uint32_t vectors[]__attribute__((section(".vectors")))={
	(uint32_t)&_STACK_TOP,
	(uint32_t)&Reset_handler,
	(uint32_t)&NMI_Handler
} ;

extern uint32_t _E_text ;
extern uint32_t _S_data ;
extern uint32_t _E_data ;
extern uint32_t _S_bss ;
extern uint32_t _E_bss ;

void Reset_handler(){
	int i = 0 ; 
	// copy data section from flash to ram 
	unsigned char DATA_size = (unsigned char *)&_E_data - (unsigned char *)&_S_data ; 
	unsigned char* p_source = (unsigned char*)&_E_text;
	unsigned char* p_dest   = (unsigned char*)&_S_data;
	for(i=0; i<DATA_size; i++)
	{
		*((unsigned char *)p_dest++) = *((unsigned char *)p_source++) ; 
	}
	// initialize bss 
	DATA_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss ; 
	p_dest = (unsigned char *)&_S_bss;
	for(i=0 ; i<DATA_size; i++)
	{
		*((unsigned char *)p_dest++) = (unsigned char )0 ; 
	}
	// jump to main
	main();
	}


	