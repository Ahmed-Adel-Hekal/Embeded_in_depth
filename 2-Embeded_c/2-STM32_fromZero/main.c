typedef unsigned int vuint32_t;
#define RCC_BASE 	0x40021000
#define GPIOA_BASE 	0x40010800
#define RCC_APB2ENR	*(vuint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH	*(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR	*(vuint32_t *)(GPIOA_BASE + 0x0C)


volatile char bss[100];
volatile char data[100]={1,2,3};
char const ro[100]={1,2,3};

int main(){
	int i ; 
	RCC_APB2ENR |= (1<<2);
	GPIOA_CRH 	&= 0xff0fffff;
	GPIOA_CRH	|=	0x00200000;
	bss[1] = 10 ;
	while(1){
		GPIOA_ODR ^= (1<<13);
		for(i =0;i<5000;i++);
	}
}