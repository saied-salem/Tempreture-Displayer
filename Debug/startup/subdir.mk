################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../startup/startup_stm32.s 

OBJS += \
./startup/startup_stm32.o 


# Each subdirectory must supply rules for building sources it contributes
startup/%.o: ../startup/%.s
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Assembler'
	@echo $(PWD)
	arm-none-eabi-as -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -I"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/StdPeriph_Driver/inc" -I"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/inc" -I"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/CMSIS/device" -I"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/CMSIS/core" -g -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


