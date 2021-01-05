################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/hw/driver/cli.c \
../src/hw/driver/i2c.c \
../src/hw/driver/led.c \
../src/hw/driver/timer.c \
../src/hw/driver/uart.c 

OBJS += \
./src/hw/driver/cli.o \
./src/hw/driver/i2c.o \
./src/hw/driver/led.o \
./src/hw/driver/timer.o \
./src/hw/driver/uart.o 

C_DEPS += \
./src/hw/driver/cli.d \
./src/hw/driver/i2c.d \
./src/hw/driver/led.d \
./src/hw/driver/timer.d \
./src/hw/driver/uart.d 


# Each subdirectory must supply rules for building sources it contributes
src/hw/driver/cli.o: ../src/hw/driver/cli.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/cli.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/hw/driver/i2c.o: ../src/hw/driver/i2c.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/i2c.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/hw/driver/led.o: ../src/hw/driver/led.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/led.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/hw/driver/timer.o: ../src/hw/driver/timer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/timer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/hw/driver/uart.o: ../src/hw/driver/uart.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/hw/driver/uart.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

