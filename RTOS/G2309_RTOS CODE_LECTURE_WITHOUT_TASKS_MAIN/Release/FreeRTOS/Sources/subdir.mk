################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../FreeRTOS/Sources/croutine.c \
../FreeRTOS/Sources/heap_1.c \
../FreeRTOS/Sources/list.c \
../FreeRTOS/Sources/port.c \
../FreeRTOS/Sources/queue.c \
../FreeRTOS/Sources/tasks.c \
../FreeRTOS/Sources/timers.c 

OBJS += \
./FreeRTOS/Sources/croutine.o \
./FreeRTOS/Sources/heap_1.o \
./FreeRTOS/Sources/list.o \
./FreeRTOS/Sources/port.o \
./FreeRTOS/Sources/queue.o \
./FreeRTOS/Sources/tasks.o \
./FreeRTOS/Sources/timers.o 

C_DEPS += \
./FreeRTOS/Sources/croutine.d \
./FreeRTOS/Sources/heap_1.d \
./FreeRTOS/Sources/list.d \
./FreeRTOS/Sources/port.d \
./FreeRTOS/Sources/queue.d \
./FreeRTOS/Sources/tasks.d \
./FreeRTOS/Sources/timers.d 


# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/Sources/%.o: ../FreeRTOS/Sources/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\Common" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\FreeRTOS\Config" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\FreeRTOS\Include" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\FreeRTOS\Sources" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\HAL" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\MCAL" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks\SERVICES" -I"F:\WorkSpaces\Workspace_Eclipse\G2309_P02_FreeRTOS_Periodic_Tasks" -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


