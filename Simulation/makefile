#@copyrights : Ahmed Hekal 
CC=arm-none-eabi-
CFLAGS= -mcpu=cortex-m3 -mthumb -gdwarf-2
INCS=-I .
LIBS= 
SRC=$(wildcard *.c)
OBJ=$(SRC:.c=.o)
AS=$(wildcard *.s)
ASOBJ=$(AS:.s=.o)
Project_name=Cortex_lab

all:$(Project_name).bin
	@echo "=================Build is Done============"
	
#startup.o:startup.s
#	$(CC)as.exe $(CFLAGS) $< -o $@

%.o: %.c 
	$(CC)gcc.exe -c $(CFLAGS) $(INCS) $< -o $@

$(Project_name).elf:$(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linker.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@ -Map=$(Project_name).map
	

$(Project_name).bin:$(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	
 
clean_all:
	rm *.o *.bin *.elf