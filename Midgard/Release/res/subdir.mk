################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../res/BitVector.cpp \
../res/crazythread.cpp \
../res/nodoMatriz.cpp \
../res/randomClass.cpp 

OBJS += \
./res/BitVector.o \
./res/crazythread.o \
./res/nodoMatriz.o \
./res/randomClass.o 

CPP_DEPS += \
./res/BitVector.d \
./res/crazythread.d \
./res/nodoMatriz.d \
./res/randomClass.d 


# Each subdirectory must supply rules for building sources it contributes
res/%.o: ../res/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


