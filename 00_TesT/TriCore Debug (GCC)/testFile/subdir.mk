################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../testFile/source.c 

C_DEPS += \
./testFile/source.d 

OBJS += \
./testFile/source.o 


# Each subdirectory must supply rules for building sources it contributes
testFile/%.o: ../testFile/%.c testFile/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/FM23/AURIX-v1.10.2-workspace/00_TesT/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-testFile

clean-testFile:
	-$(RM) ./testFile/source.d ./testFile/source.o

.PHONY: clean-testFile

