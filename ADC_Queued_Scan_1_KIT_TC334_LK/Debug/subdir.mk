################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_Queued_Scan.c \
../Cpu0_Main.c 

COMPILED_SRCS += \
ADC_Queued_Scan.src \
Cpu0_Main.src 

C_DEPS += \
ADC_Queued_Scan.d \
Cpu0_Main.d 

OBJS += \
ADC_Queued_Scan.o \
Cpu0_Main.o 


# Each subdirectory must supply rules for building sources it contributes
ADC_Queued_Scan.src: ../ADC_Queued_Scan.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -DIFX_SSW_PREMAIN -DIFX_SSW_POSTMAIN -D__CPU__=tc33x "-fC:/Users/FM23/AURIX-v1.10.2-workspace/ADC_Queued_Scan_1_KIT_TC334_LK/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
ADC_Queued_Scan.o: ADC_Queued_Scan.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
Cpu0_Main.src: ../Cpu0_Main.c subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -DIFX_SSW_PREMAIN -DIFX_SSW_POSTMAIN -D__CPU__=tc33x "-fC:/Users/FM23/AURIX-v1.10.2-workspace/ADC_Queued_Scan_1_KIT_TC334_LK/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
Cpu0_Main.o: Cpu0_Main.src subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean--2e-

clean--2e-:
	-$(RM) ADC_Queued_Scan.d ADC_Queued_Scan.o ADC_Queued_Scan.src Cpu0_Main.d Cpu0_Main.o Cpu0_Main.src

.PHONY: clean--2e-

