#Copyright : Ahmed Adel 
# In this make file i will try to use all possible way to 
# cover all Makefile 
# I will comment for each line descriping what happens 

# target : dependecies
# <-tab-> your commands
#----------------------------------------------------------------------------------------
# Called Automatic Variables
# $@: 
#   This variable holds the file name of the target of the rule. It is often used when you want to refer to the target file name within the recipe.
# $<: 
#	This variable holds the file name of the first prerequisite of the rule. It is typically used when the rule has multiple prerequisites, and you want to refer to the first prerequisite within the recipe.
# $^: 
#	This variable holds the file names of all the prerequisites of the rule, with duplicates removed. It is useful when you want to refer to all the prerequisites within the recipe.
# $?: 
#	This variable holds the file names of all the prerequisites that are newer than the target. It is commonly used when you want to rebuild the target only if any of its prerequisites have changed.
# $*: 
#	This variable holds the stem of the target file name (i.e., the file name without the file extension). It is often used when you want to perform operations on the stem of the target file name within the recipe.
#----------------------------------------------------------------------------------------

# This line will include makeconf file 
include makeconf

# This is used to enable debug or diable it 
ifeq ($(debug),1)
C_flags= -c -g $(INCLUDES) -mcpu=$(PROCESSOR)
ass_flags= -g -mcpu=$(PROCESSOR)
DEBUG_MESSAGE = Debug is Enable
else
C_flags= -c  $(INCLUDES) -mcpu=$(PROCESSOR)
ass_flags=  -mcpu=$(PROCESSOR)
DEBUG_MESSAGE = Debug is Disabled
endif

#This gets all files name 
c_files = $(wildcard *.c)
o_files = $(c_files:.c=.o)
As_files= $(wildcard *.s)
As_obj  = $(As_files:.s=.o)
Objects = $(wildcard *.o)


# Rule to Create .bin file 
all : $(bin_name).bin
	@echo "==========================================="
	@echo "               Build Succeded"
	@echo "==========================================="

# Rule to Create .bin file Using name provided in bin_name Variable
$(bin_name).bin : $(bin_name).elf 
	@echo "Creating Binary file using this files "
#	 $(foreach i,$(o_files), echo "=================\n")
# Iterate Over .o files and print it is names 
	@for file in $(wildcard *.o); do \
		echo "$$file"; \
	done
#	@ls *.o
# Command used to create bin file and 
	$(CC_path)objcopy.exe  $(excutable_type) $(bin_name).elf  $(bin_name).bin
	@echo "Creating Binary file using this flags $(excutable_type)"
	@echo "Binary file name is $(bin_name)"
	@echo "==========================================="

# Create .elf files Using Linker
$(bin_name).elf:$(o_files) $(As_obj)
	@echo "---------Linker Started---------"
# Get all Object files Linked $@ to use .elf 
# $^ to use all prerequest
	$(CC_path)ld.exe -T linker.ld $^ -o $@ -Map=$(bin_name).map
	@echo "==========================================="


%.o: %.c 

	@echo "$(DEBUG_MESSAGE)"
	@echo "---------Compilation Started---------"
	$(CC_path)gcc.exe $(C_flags) $^ -o $@ 
	@echo "==========================================="


	
$(startupFile).o: $(startupFile).s
	@echo "---------Assembler Started $<---------"
	$(CC_path)as.exe  $(ass_flags) $^ -o $@
	@echo "==========================================="
	


check_compiler:
	echo "$(PATH|grep arm-none-eabi)"
	compiler = $(CC_path)gcc.exe
	@echo $(compiler)
    # $(if $(wildcard $(compiler)),,$(error "$(compiler) not found in PATH"))


clean :
	rm *.o *.elf *.bin