################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../HAL/H_LCD_Driver/H_LCD.c 

OBJS += \
./HAL/H_LCD_Driver/H_LCD.o 

C_DEPS += \
./HAL/H_LCD_Driver/H_LCD.d 


# Each subdirectory must supply rules for building sources it contributes
HAL/H_LCD_Driver/%.o: ../HAL/H_LCD_Driver/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


