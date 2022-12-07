################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include startup/subdir.mk
-include src/subdir.mk
-include Drivers/Src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: ADC_project_22.elf

# Tool invocations
ADC_project_22.elf: $(OBJS) $(USER_OBJS) E:\Bio-Medical\ materials\Faculty\ of\ Engneering\Third\ year\Second\ term\Embedded\ADC_Project\ADC_project_driver\ADC_project_22/LinkerScript.ld
	@echo 'Building target: $@'
	@echo 'Invoking: MCU GCC Linker'
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -T"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/LinkerScript.ld" -Wl,-Map=output.map -Wl,--gc-sections -o "ADC_project_22.elf" @"objects.list" $(USER_OBJS) $(LIBS) -lm
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) *
	-@echo ' '

post-build:
	-@echo 'Generating binary and Printing size information:'
	arm-none-eabi-objcopy -O ihex "ADC_project_22.elf" "ADC_project_22.hex"
	arm-none-eabi-size "ADC_project_22.elf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
