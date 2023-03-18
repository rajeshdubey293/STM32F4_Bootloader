################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Task\ Schedular/Src/main.c \
../Task\ Schedular/Src/stm32f4xx_hal_msp.c \
../Task\ Schedular/Src/stm32f4xx_it.c \
../Task\ Schedular/Src/syscalls.c \
../Task\ Schedular/Src/sysmem.c \
../Task\ Schedular/Src/system_stm32f4xx.c 

OBJS += \
./Task\ Schedular/Src/main.o \
./Task\ Schedular/Src/stm32f4xx_hal_msp.o \
./Task\ Schedular/Src/stm32f4xx_it.o \
./Task\ Schedular/Src/syscalls.o \
./Task\ Schedular/Src/sysmem.o \
./Task\ Schedular/Src/system_stm32f4xx.o 

C_DEPS += \
./Task\ Schedular/Src/main.d \
./Task\ Schedular/Src/stm32f4xx_hal_msp.d \
./Task\ Schedular/Src/stm32f4xx_it.d \
./Task\ Schedular/Src/syscalls.d \
./Task\ Schedular/Src/sysmem.d \
./Task\ Schedular/Src/system_stm32f4xx.d 


# Each subdirectory must supply rules for building sources it contributes
Task\ Schedular/Src/main.o: ../Task\ Schedular/Src/main.c Task\ Schedular/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Task Schedular/Src/main.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Task\ Schedular/Src/stm32f4xx_hal_msp.o: ../Task\ Schedular/Src/stm32f4xx_hal_msp.c Task\ Schedular/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Task Schedular/Src/stm32f4xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Task\ Schedular/Src/stm32f4xx_it.o: ../Task\ Schedular/Src/stm32f4xx_it.c Task\ Schedular/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Task Schedular/Src/stm32f4xx_it.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Task\ Schedular/Src/syscalls.o: ../Task\ Schedular/Src/syscalls.c Task\ Schedular/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Task Schedular/Src/syscalls.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Task\ Schedular/Src/sysmem.o: ../Task\ Schedular/Src/sysmem.c Task\ Schedular/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Task Schedular/Src/sysmem.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"
Task\ Schedular/Src/system_stm32f4xx.o: ../Task\ Schedular/Src/system_stm32f4xx.c Task\ Schedular/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32F429I_DISC1 -DSTM32 -DSTM32F429ZITx -DSTM32F4 -DSTM32F429xx -DUSE_HAL_DRIVER=1 -c -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/BSP/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Upgrade Application/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Serial Communication/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Task Schedular/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/CMSIS/Device/ST/STM32F4xx/Include" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc" -I"/home/vicky/STM32CubeIDE/workspace_1.11.0/STM32F4_Bootloader/Drivers/STM32F4xx_HAL_Driver/Inc/Legacy" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"Task Schedular/Src/system_stm32f4xx.d" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Task-20-Schedular-2f-Src

clean-Task-20-Schedular-2f-Src:
	-$(RM) ./Task\ Schedular/Src/main.d ./Task\ Schedular/Src/main.o ./Task\ Schedular/Src/main.su ./Task\ Schedular/Src/stm32f4xx_hal_msp.d ./Task\ Schedular/Src/stm32f4xx_hal_msp.o ./Task\ Schedular/Src/stm32f4xx_hal_msp.su ./Task\ Schedular/Src/stm32f4xx_it.d ./Task\ Schedular/Src/stm32f4xx_it.o ./Task\ Schedular/Src/stm32f4xx_it.su ./Task\ Schedular/Src/syscalls.d ./Task\ Schedular/Src/syscalls.o ./Task\ Schedular/Src/syscalls.su ./Task\ Schedular/Src/sysmem.d ./Task\ Schedular/Src/sysmem.o ./Task\ Schedular/Src/sysmem.su ./Task\ Schedular/Src/system_stm32f4xx.d ./Task\ Schedular/Src/system_stm32f4xx.o ./Task\ Schedular/Src/system_stm32f4xx.su

.PHONY: clean-Task-20-Schedular-2f-Src

