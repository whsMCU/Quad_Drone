################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/common/core/eeprom.c \
../src/common/core/filter.c \
../src/common/core/gps.c \
../src/common/core/imu.c \
../src/common/core/led_control.c \
../src/common/core/mixer.c \
../src/common/core/pid.c \
../src/common/core/radio.c \
../src/common/core/ring_buffer.c \
../src/common/core/sensor.c \
../src/common/core/telemetry.c 

OBJS += \
./src/common/core/eeprom.o \
./src/common/core/filter.o \
./src/common/core/gps.o \
./src/common/core/imu.o \
./src/common/core/led_control.o \
./src/common/core/mixer.o \
./src/common/core/pid.o \
./src/common/core/radio.o \
./src/common/core/ring_buffer.o \
./src/common/core/sensor.o \
./src/common/core/telemetry.o 

C_DEPS += \
./src/common/core/eeprom.d \
./src/common/core/filter.d \
./src/common/core/gps.d \
./src/common/core/imu.d \
./src/common/core/led_control.d \
./src/common/core/mixer.d \
./src/common/core/pid.d \
./src/common/core/radio.d \
./src/common/core/ring_buffer.d \
./src/common/core/sensor.d \
./src/common/core/telemetry.d 


# Each subdirectory must supply rules for building sources it contributes
src/common/core/eeprom.o: ../src/common/core/eeprom.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/eeprom.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/filter.o: ../src/common/core/filter.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/filter.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/gps.o: ../src/common/core/gps.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/gps.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/imu.o: ../src/common/core/imu.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/imu.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/led_control.o: ../src/common/core/led_control.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/led_control.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/mixer.o: ../src/common/core/mixer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/mixer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/pid.o: ../src/common/core/pid.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/pid.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/radio.o: ../src/common/core/radio.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/radio.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/ring_buffer.o: ../src/common/core/ring_buffer.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/ring_buffer.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/sensor.o: ../src/common/core/sensor.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/sensor.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/common/core/telemetry.o: ../src/common/core/telemetry.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/common/core/telemetry.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

