################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.c 

COMPILED_SRCS += \
Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.src 

C_DEPS += \
Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.d 

OBJS += \
Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.src: ../Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.c Libraries/iLLD/TC29B/Tricore/Cpu/Trap/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc29xb "-fC:/Users/FM23/AURIX-v1.10.2-workspace/First_Project/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc29xb -Y0 -N0 -Z0 -o "$@" "$<"
Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.o: Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.src Libraries/iLLD/TC29B/Tricore/Cpu/Trap/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Cpu-2f-Trap

clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Cpu-2f-Trap:
	-$(RM) Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.d Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.o Libraries/iLLD/TC29B/Tricore/Cpu/Trap/IfxCpu_Trap.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC29B-2f-Tricore-2f-Cpu-2f-Trap

