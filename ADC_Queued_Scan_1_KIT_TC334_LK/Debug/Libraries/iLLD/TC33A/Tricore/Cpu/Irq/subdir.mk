################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.c 

COMPILED_SRCS += \
Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.src 

C_DEPS += \
Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.d 

OBJS += \
Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.src: ../Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.c Libraries/iLLD/TC33A/Tricore/Cpu/Irq/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -DIFX_SSW_PREMAIN -DIFX_SSW_POSTMAIN -D__CPU__=tc33x "-fC:/Users/FM23/AURIX-v1.10.2-workspace/ADC_Queued_Scan_1_KIT_TC334_LK/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.o: Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.src Libraries/iLLD/TC33A/Tricore/Cpu/Irq/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-iLLD-2f-TC33A-2f-Tricore-2f-Cpu-2f-Irq

clean-Libraries-2f-iLLD-2f-TC33A-2f-Tricore-2f-Cpu-2f-Irq:
	-$(RM) Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.d Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.o Libraries/iLLD/TC33A/Tricore/Cpu/Irq/IfxCpu_Irq.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC33A-2f-Tricore-2f-Cpu-2f-Irq

