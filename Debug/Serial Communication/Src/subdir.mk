################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Serial\ Communication/Src/SC_Process.c 

OBJS += \
./Serial\ Communication/Src/SC_Process.o 

C_DEPS += \
./Serial\ Communication/Src/SC_Process.d 


# Each subdirectory must supply rules for building sources it contributes
Serial\ Communication/Src/SC_Process.o: ../Serial\ Communication/Src/SC_Process.c Serial\ Communication/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Serial Communication/Src/SC_Process.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Serial-20-Communication-2f-Src

clean-Serial-20-Communication-2f-Src:
	-$(RM) ./Serial\ Communication/Src/SC_Process.d ./Serial\ Communication/Src/SC_Process.o ./Serial\ Communication/Src/SC_Process.su

.PHONY: clean-Serial-20-Communication-2f-Src

