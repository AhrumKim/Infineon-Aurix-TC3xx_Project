################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.asm.c \
../Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.c \
../Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_Fifo.c 

C_DEPS += \
./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.asm.d \
./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.d \
./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_Fifo.d 

OBJS += \
./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.asm.o \
./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.o \
./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_Fifo.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/%.o: ../Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/%.c Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AURIX GCC Compiler'
	tricore-elf-gcc -std=c99 "@C:/Users/FM23/AURIX-v1.10.2-workspace/00_TesT/TriCore Debug (GCC)/AURIX_GCC_Compiler-Include_paths__-I_.opt" -Og -g3 -gdwarf-3 -Wall -c -fmessage-length=0 -fno-common -fstrict-volatile-bitfields -fdata-sections -ffunction-sections -mtc161 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-_Lib-2f-DataHandling

clean-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-_Lib-2f-DataHandling:
	-$(RM) ./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.asm.d ./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.asm.o ./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.d ./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_CircularBuffer.o ./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_Fifo.d ./Libraries/iLLD/TC27D/Tricore/_Lib/DataHandling/Ifx_Fifo.o

.PHONY: clean-Libraries-2f-iLLD-2f-TC27D-2f-Tricore-2f-_Lib-2f-DataHandling

