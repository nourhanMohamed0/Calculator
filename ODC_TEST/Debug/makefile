################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/M_Timer_Driver/subdir.mk
-include MCAL/M_DIO_Driver/subdir.mk
-include HAL/H_Seven_Segment/subdir.mk
-include HAL/H_LCD_Driver/subdir.mk
-include HAL/H_KeyPad_Driver/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
ODC_TEST.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: ODC_TEST.elf secondary-outputs

# Tool invocations
ODC_TEST.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ODC_TEST.map -mmcu=atmega32 -o "ODC_TEST.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ODC_TEST.lss: ODC_TEST.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ODC_TEST.elf  >"ODC_TEST.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ODC_TEST.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ODC_TEST.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ODC_TEST.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
