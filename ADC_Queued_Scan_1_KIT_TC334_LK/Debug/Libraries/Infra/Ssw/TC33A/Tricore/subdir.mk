################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.c \
../Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.c 

COMPILED_SRCS += \
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.src \
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.src 

C_DEPS += \
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.d \
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.d 

OBJS += \
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.o \
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.src: ../Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.c Libraries/Infra/Ssw/TC33A/Tricore/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -DIFX_SSW_PREMAIN -DIFX_SSW_POSTMAIN -D__CPU__=tc33x "-fC:/Users/FM23/AURIX-v1.10.2-workspace/ADC_Queued_Scan_1_KIT_TC334_LK/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.o: Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.src Libraries/Infra/Ssw/TC33A/Tricore/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.src: ../Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.c Libraries/Infra/Ssw/TC33A/Tricore/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -DIFX_SSW_PREMAIN -DIFX_SSW_POSTMAIN -D__CPU__=tc33x "-fC:/Users/FM23/AURIX-v1.10.2-workspace/ADC_Queued_Scan_1_KIT_TC334_LK/Debug/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc33x -Y0 -N0 -Z0 -o "$@" "$<"
Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.o: Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.src Libraries/Infra/Ssw/TC33A/Tricore/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-Infra-2f-Ssw-2f-TC33A-2f-Tricore

clean-Libraries-2f-Infra-2f-Ssw-2f-TC33A-2f-Tricore:
	-$(RM) Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.d Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.o Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Infra.src Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.d Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.o Libraries/Infra/Ssw/TC33A/Tricore/Ifx_Ssw_Tc0.src

.PHONY: clean-Libraries-2f-Infra-2f-Ssw-2f-TC33A-2f-Tricore

