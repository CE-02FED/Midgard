################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../logicRazas/DarkElves.cpp \
../logicRazas/Dwarves.cpp \
../logicRazas/Elves.cpp \
../logicRazas/Giants.cpp 

OBJS += \
./logicRazas/DarkElves.o \
./logicRazas/Dwarves.o \
./logicRazas/Elves.o \
./logicRazas/Giants.o 

CPP_DEPS += \
./logicRazas/DarkElves.d \
./logicRazas/Dwarves.d \
./logicRazas/Elves.d \
./logicRazas/Giants.d 


# Each subdirectory must supply rules for building sources it contributes
logicRazas/%.o: ../logicRazas/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


