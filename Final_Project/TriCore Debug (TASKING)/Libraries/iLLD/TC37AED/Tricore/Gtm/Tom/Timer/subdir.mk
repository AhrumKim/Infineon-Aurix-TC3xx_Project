################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.c 

COMPILED_SRCS += \
Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.src 

C_DEPS += \
Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.d 

OBJS += \
Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.o 


# Each subdirectory must supply rules for building sources it contributes
Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.src: ../Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.c Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/subdir.mk
	cctc -cs --dep-file="$(*F).d" --misrac-version=2004 -D__CPU__=tc37x "-fC:/Users/FM23/AURIX-v1.10.2-workspace/Final_Project/TriCore Debug (TASKING)/TASKING_C_C___Compiler-Include_paths__-I_.opt" --iso=99 --c++14 --language=+volatile --exceptions --anachronisms --fp-model=3 -O0 --tradeoff=4 --compact-max-size=200 -g -Wc-w544 -Wc-w557 -Ctc37x -Y0 -N0 -Z0 -o "$@" "$<"
Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.o: Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.src Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/subdir.mk
	astc -Og -Os --no-warnings= --error-limit=42 -o  "$@" "$<"

clean: clean-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Gtm-2f-Tom-2f-Timer

clean-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Gtm-2f-Tom-2f-Timer:
	-$(RM) Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.d Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.o Libraries/iLLD/TC37AED/Tricore/Gtm/Tom/Timer/IfxGtm_Tom_Timer.src

.PHONY: clean-Libraries-2f-iLLD-2f-TC37AED-2f-Tricore-2f-Gtm-2f-Tom-2f-Timer

