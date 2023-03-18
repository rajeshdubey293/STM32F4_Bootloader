################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../BSP/Src/Flash.c \
../BSP/Src/GPIO.c \
../BSP/Src/TIM.c \
../BSP/Src/UART.c 

OBJS += \
./BSP/Src/Flash.o \
./BSP/Src/GPIO.o \
./BSP/Src/TIM.o \
./BSP/Src/UART.o 

C_DEPS += \
./BSP/Src/Flash.d \
./BSP/Src/GPIO.d \
./BSP/Src/TIM.d \
./BSP/Src/UART.d 


# Each subdirectory must supply rules for building sources it contributes
BSP/Src/%.o BSP/Src/%.su: ../BSP/Src/%.c BSP/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-BSP-2f-Src

clean-BSP-2f-Src:
	-$(RM) ./BSP/Src/Flash.d ./BSP/Src/Flash.o ./BSP/Src/Flash.su ./BSP/Src/GPIO.d ./BSP/Src/GPIO.o ./BSP/Src/GPIO.su ./BSP/Src/TIM.d ./BSP/Src/TIM.o ./BSP/Src/TIM.su ./BSP/Src/UART.d ./BSP/Src/UART.o ./BSP/Src/UART.su

.PHONY: clean-BSP-2f-Src

