################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include Libraries/iLLD/TC33A/Tricore/_PinMap/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/_Impl/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Src/Std/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Scu/Std/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Port/Std/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Port/Io/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Pms/Std/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Mtu/Std/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Gtm/Std/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Evadc/Std/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Evadc/Adc/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Cpu/Trap/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Cpu/Std/subdir.mk
-include Libraries/iLLD/TC33A/Tricore/Cpu/Irq/subdir.mk
-include Libraries/Infra/Ssw/TC33A/Tricore/subdir.mk
-include Libraries/Infra/Platform/Tricore/Compilers/subdir.mk
-include Libraries/subdir.mk
-include Configurations/Debug/subdir.mk
-include Configurations/subdir.mk
-include subdir.mk
ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
endif

-include ../makefile.defs

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := ADC_Queued_Scan_1_KIT_TC334_LK
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
SECONDARY_SIZE += \
ADC_Queued_Scan_1_KIT_TC334_LK.siz \


# All Target
all: main-build

# Main-build Target
main-build: ADC_Queued_Scan_1_KIT_TC334_LK.elf secondary-outputs

# Tool invocations
ADC_Queued_Scan_1_KIT_TC334_LK.elf: $(OBJS) makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: TASKING Linker'
	cctc --lsl-file="../Lcf_Tasking_Tricore_Tc.lsl" -Wl-Oc -Wl-OL -Wl-Ot -Wl-Ox -Wl-Oy -Wl--map-file="ADC_Queued_Scan_1_KIT_TC334_LK.map" -Wl-mc -Wl-mf -Wl-mi -Wl-mk -Wl-ml -Wl-mm -Wl-md -Wl-mr -Wl-mu --no-warnings= -Wl--error-limit=42 --fp-model=3 -lrt --lsl-core=vtc --exceptions --strict --anachronisms --force-c++ -Ctc33x -o"ADC_Queued_Scan_1_KIT_TC334_LK.elf" -Wl-o"ADC_Queued_Scan_1_KIT_TC334_LK.hex:IHEX" $(OBJS)
	@echo 'Finished building target: $@'
	@echo ' '

ADC_Queued_Scan_1_KIT_TC334_LK.siz: ADC_Queued_Scan_1_KIT_TC334_LK.elf makefile $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	elfsize  "ADC_Queued_Scan_1_KIT_TC334_LK.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) ADC_Queued_Scan_1_KIT_TC334_LK.siz ADC_Queued_Scan_1_KIT_TC334_LK.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_SIZE)

.PHONY: all clean dependents main-build

-include ../makefile.targets
