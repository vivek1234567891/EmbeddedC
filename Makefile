Proj_name=case_study
Buld_dir=Build


#All source code files
SRC=src/Avtivity_01.c\
src/Activity_02.c\
src/Action_03.c\
main.c\
fuse.c\

INC= -I inc 
ifdef OS	# All configurations for Windwos OS
# Correct the path based on OS
   FixPath = $(subst /,\,$1)
# Name of the compiler used
   CC = avr-gcc.exe
# Name of the elf to hex file converter used
   AVR_OBJ_CPY = avr-objcopy.exe
else #All configurations for Linux OS
   ifeq ($(shell uname), Linux)
# Correct the path based on OS
      FixPath = $1				
# Name of the compiler used
	  CC = avr-gcc
# Name of the elf to hex file converter used
	  AVR_OBJ_CPY = avr-objcopy 
   endif
endif

# Command to make to consider these names as targets and not as file names in folder
.PHONY:all analysis clean doc

all:$(BUILD_DIR)
# Compile the code and generate the ELF file
	$(CC) -g -Wall -Os -mmcu=atmega328 -DF_CPU=16000000UL  $(INC) $(SRC) -o $(call FixPath,$(BUILD_DIR)/$(PROJ_NAME).elf)

$(BUILD_DIR):
# Create directory to store the built files
	mkdir $(BUILD_DIR)

analysis: $(SRC)
# Analyse the code using Cppcheck command line utility
	cppcheck --enable=all $^
doc:
# Build the code code documentation using Doxygen command line utility
	make -C documentation

clean:
# Remove all the build files and generated document files
	rm -rf $(call FixPath,$(BUILD_DIR)/*)
	make -C documentation clean