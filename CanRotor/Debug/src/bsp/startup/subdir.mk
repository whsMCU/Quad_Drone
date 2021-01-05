################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
S_SRCS += \
../src/bsp/startup/startup_stm32f103cbtx.s 

OBJS += \
./src/bsp/startup/startup_stm32f103cbtx.o 

S_DEPS += \
./src/bsp/startup/startup_stm32f103cbtx.d 


# Each subdirectory must supply rules for building sources it contributes
src/bsp/startup/startup_stm32f103cbtx.o: ../src/bsp/startup/startup_stm32f103cbtx.s
	arm-none-eabi-gcc -mcpu=cortex-m3 -g3 -c -x assembler-with-cpp -MMD -MP -MF"src/bsp/startup/startup_stm32f103cbtx.d" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@" "$<"

