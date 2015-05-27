################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../logicFacade/LogicFacade.cpp 

OBJS += \
./logicFacade/LogicFacade.o 

CPP_DEPS += \
./logicFacade/LogicFacade.d 


# Each subdirectory must supply rules for building sources it contributes
logicFacade/%.o: ../logicFacade/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


