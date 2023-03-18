################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Upgrade\ Application/Src/Upgrade_Application.c 

OBJS += \
./Upgrade\ Application/Src/Upgrade_Application.o 

C_DEPS += \
./Upgrade\ Application/Src/Upgrade_Application.d 


# Each subdirectory must supply rules for building sources it contributes
Upgrade\ Application/Src/Upgrade_Application.o: ../Upgrade\ Application/Src/Upgrade_Application.c Upgrade\ Application/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Upgrade Application/Src/Upgrade_Application.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Upgrade-20-Application-2f-Src

clean-Upgrade-20-Application-2f-Src:
	-$(RM) ./Upgrade\ Application/Src/Upgrade_Application.d ./Upgrade\ Application/Src/Upgrade_Application.o ./Upgrade\ Application/Src/Upgrade_Application.su

.PHONY: clean-Upgrade-20-Application-2f-Src

