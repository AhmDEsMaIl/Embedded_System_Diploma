################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/LCD.c 

OBJS += \
./HAL/LCD.o 

C_DEPS += \
./HAL/LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/%.o: ../HAL/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\Common" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\FreeRTOS\Config" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\FreeRTOS\Include" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\FreeRTOS\Sources" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\HAL" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\MCAL" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\SERVICES" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


