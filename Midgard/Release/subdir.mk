################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../Individuals.cpp \
../MainLogic.cpp \
../genetic_tutorial.cpp \
../main.cpp 

OBJS += \
./Individuals.o \
./MainLogic.o \
./genetic_tutorial.o \
./main.o 

CPP_DEPS += \
./Individuals.d \
./MainLogic.d \
./genetic_tutorial.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


