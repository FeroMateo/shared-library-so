################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/SharedUtils.c \
../src/utils_cliente.c \
../src/utils_servidor.c 

OBJS += \
./src/SharedUtils.o \
./src/utils_cliente.o \
./src/utils_servidor.o 

C_DEPS += \
./src/SharedUtils.d \
./src/utils_cliente.d \
./src/utils_servidor.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I"/home/utnso/shared-library-so/SharedUtils/src" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


