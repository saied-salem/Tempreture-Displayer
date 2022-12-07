################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Src/ADC.c \
../Drivers/Src/LCD.c \
../Drivers/Src/gpio.c 

OBJS += \
./Drivers/Src/ADC.o \
./Drivers/Src/LCD.o \
./Drivers/Src/gpio.o 

C_DEPS += \
./Drivers/Src/ADC.d \
./Drivers/Src/LCD.d \
./Drivers/Src/gpio.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Src/%.o: ../Drivers/Src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU GCC Compiler'
	@echo $(PWD)
	arm-none-eabi-gcc -mcpu=cortex-m4 -mthumb -mfloat-abi=hard -mfpu=fpv4-sp-d16 -DSTM32 -DSTM32F4 -DSTM32F401CCUx -DDEBUG -DSTM32F401xx -I"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/Drivers/Include" -I"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/inc" -I"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/CMSIS/device" -I"E:/Bio-Medical materials/Faculty of Engneering/Third year/Second term/Embedded/ADC_Project/ADC_project_driver/ADC_project_22/CMSIS/core" -O0 -g3 -Wall -fmessage-length=0 -ffunction-sections -c -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


