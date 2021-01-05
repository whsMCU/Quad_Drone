################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/bsp/bsp.c \
../src/bsp/stm32f1xx_hal_msp.c \
../src/bsp/stm32f1xx_it.c \
../src/bsp/syscalls.c \
../src/bsp/sysmem.c \
../src/bsp/system_stm32f1xx.c 

OBJS += \
./src/bsp/bsp.o \
./src/bsp/stm32f1xx_hal_msp.o \
./src/bsp/stm32f1xx_it.o \
./src/bsp/syscalls.o \
./src/bsp/sysmem.o \
./src/bsp/system_stm32f1xx.o 

C_DEPS += \
./src/bsp/bsp.d \
./src/bsp/stm32f1xx_hal_msp.d \
./src/bsp/stm32f1xx_it.d \
./src/bsp/syscalls.d \
./src/bsp/sysmem.d \
./src/bsp/system_stm32f1xx.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/bsp.o: ../src/bsp/bsp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/bsp/bsp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/bsp/stm32f1xx_hal_msp.o: ../src/bsp/stm32f1xx_hal_msp.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/bsp/stm32f1xx_hal_msp.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/bsp/stm32f1xx_it.o: ../src/bsp/stm32f1xx_it.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/bsp/stm32f1xx_it.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/bsp/syscalls.o: ../src/bsp/syscalls.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/bsp/syscalls.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/bsp/sysmem.o: ../src/bsp/sysmem.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/bsp/sysmem.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"
src/bsp/system_stm32f1xx.o: ../src/bsp/system_stm32f1xx.c
	arm-none-eabi-gcc "$<" -mcpu=cortex-m3 -std=gnu11 -g3 -DSTM32F103xB -DSTM32 -DSTM32F103CBTx -DSTM32F1 -DDEBUG -c -I"D:/STM32CubeIDE/CanRotor/src" -I"D:/STM32CubeIDE/CanRotor/src/ap" -I"D:/STM32CubeIDE/CanRotor/src/bsp" -I"D:/STM32CubeIDE/CanRotor/src/common" -I"D:/STM32CubeIDE/CanRotor/src/common/core" -I"D:/STM32CubeIDE/CanRotor/src/hw" -I"D:/STM32CubeIDE/CanRotor/src/lib" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Device/ST/STM32F1xx/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/CMSIS/Include" -I"D:/STM32CubeIDE/CanRotor/src/lib/cube_f103/Drivers/STM32F1xx_HAL_Driver/Inc" -I"D:/STM32CubeIDE/CanRotor/src/common/hw/include" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"src/bsp/system_stm32f1xx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

