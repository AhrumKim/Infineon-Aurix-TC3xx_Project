################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Configurations/Ifx_Cfg_Ssw.c \
../Configurations/Ifx_Cfg_SswBmhd.c 

COMPILED_SRCS += \
Configurations/Ifx_Cfg_Ssw.src \
Configurations/Ifx_Cfg_SswBmhd.src 

C_DEPS += \
Configurations/Ifx_Cfg_Ssw.d \
Configurations/Ifx_Cfg_SswBmhd.d 

OBJS += \
Configurations/Ifx_Cfg_Ssw.o \
Configurations/Ifx_Cfg_SswBmhd.o 


# Each subdirectory must supply rules for building sources it contributes
Configurations/Ifx_Cfg_Ssw.src: ../Configurations/Ifx_Cfg_Ssw.c Configurations/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -DIFX_SSW_PREMAIN -DIFX_SSW_POSTMAIN -D__CPU__=tc33x "-fC:/Users/FM23/AURIX-v1.10.2-workspace/ADC_Queued_Scan_1_KIT_TC334_LK/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
Configurations/Ifx_Cfg_Ssw.o: Configurations/Ifx_Cfg_Ssw.src Configurations/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
Configurations/Ifx_Cfg_SswBmhd.src: ../Configurations/Ifx_Cfg_SswBmhd.c Configurations/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -DIFX_SSW_PREMAIN -DIFX_SSW_POSTMAIN -D__CPU__=tc33x "-fC:/Users/FM23/AURIX-v1.10.2-workspace/ADC_Queued_Scan_1_KIT_TC334_LK/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
Configurations/Ifx_Cfg_SswBmhd.o: Configurations/Ifx_Cfg_SswBmhd.src Configurations/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Configurations

clean-Configurations:
	-$(RM) Configurations/Ifx_Cfg_Ssw.d Configurations/Ifx_Cfg_Ssw.o Configurations/Ifx_Cfg_Ssw.src Configurations/Ifx_Cfg_SswBmhd.d Configurations/Ifx_Cfg_SswBmhd.o Configurations/Ifx_Cfg_SswBmhd.src

.PHONY: clean-Configurations
