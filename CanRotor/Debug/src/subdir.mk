################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/main.c 

OBJS += \
./src/main.o 

C_DEPS += \
./src/main.d 


# Each subdirectory must supply rules for building sources it contributes
src/main.o: ../src/main.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/main.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

