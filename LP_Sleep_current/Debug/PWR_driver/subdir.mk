################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../PWR_driver/PWR_Driver.c 

OBJS += \
./PWR_driver/PWR_Driver.o 

C_DEPS += \
./PWR_driver/PWR_Driver.d 


# Each subdirectory must supply rules for building sources it contributes
PWR_driver/PWR_Driver.o: D:/UTSAAH_LAB-IISc_B_lore/PWR_Peripheral/LP_Sleep_current/PWR_driver/PWR_Driver.c PWR_driver/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DUSE_HAL_DRIVER -DSTM32L496xx -c -I../Core/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc -I../Drivers/STM32L4xx_HAL_Driver/Inc/Legacy -I../Drivers/CMSIS/Device/ST/STM32L4xx/Include -I../Drivers/CMSIS/Include -I"D:/UTSAAH_LAB-IISc_B_lore/PWR_Peripheral/LP_Sleep_current/PWR_driver" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-PWR_driver

clean-PWR_driver:
	-$(RM) ./PWR_driver/PWR_Driver.cyclo ./PWR_driver/PWR_Driver.d ./PWR_driver/PWR_Driver.o ./PWR_driver/PWR_Driver.su

.PHONY: clean-PWR_driver

