#@Author : Ahmed Hekal 
#@Date   : 20/2/2024
#@Description : Makefile to automate copilation process

CC=arm-none-eabi-
CFLAGS= -mthumb -mcpu=cortex-m4 -gdwarf-2 -g
INCS= -I .
LIBS=
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)
As = $(wildcard *.s)
AsOBJ = $(As:.s=.o) 
Project_name=tivac


all: $(Project_name).bin
	@echo "=========Build is Done========="
	
    
%.o: %.c
	$(CC)gcc.exe -c $(CFLAGS) $(INCS)  $< -o $@
	
$(Project_name).elf: $(OBJ) $(AsOBJ)
	$(CC)ld.exe -T Linker.ld $(LIBS) $(OBJ) -o $@ -Map=Map_file.map
	cp $(Project_name).elf $(Project_name).axf
    
	
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $< $@
    
    
clean_all:
	rm *.o *.elf *.bin
clean:
	rm *.elf *.bin

