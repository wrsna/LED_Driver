################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Drivers/Celka/Src/celka.c 

OBJS += \
./Drivers/Celka/Src/celka.o 

C_DEPS += \
./Drivers/Celka/Src/celka.d 


# Each subdirectory must supply rules for building sources it contributes
Drivers/Celka/Src/%.o Drivers/Celka/Src/%.su Drivers/Celka/Src/%.cyclo: ../Drivers/Celka/Src/%.c Drivers/Celka/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32C011xx -c -I../Core/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc -I../Drivers/STM32C0xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32C0xx/Include -I../Drivers/CMSIS/Include -I"C:/Users/Miha/STM32CubeIDE/workspace_1.15.0/CELKA/Drivers/Celka" -I"C:/Users/Miha/STM32CubeIDE/workspace_1.15.0/CELKA/Drivers/Celka/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Drivers-2f-Celka-2f-Src

clean-Drivers-2f-Celka-2f-Src:
	-$(RM) ./Drivers/Celka/Src/celka.cyclo ./Drivers/Celka/Src/celka.d ./Drivers/Celka/Src/celka.o ./Drivers/Celka/Src/celka.su

.PHONY: clean-Drivers-2f-Celka-2f-Src

