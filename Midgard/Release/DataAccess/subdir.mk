################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../DataAccess/docXML.cpp \
../DataAccess/pugixml.cpp \
../DataAccess/socketcliente.cpp \
../DataAccess/socketserver.cpp 

OBJS += \
./DataAccess/docXML.o \
./DataAccess/pugixml.o \
./DataAccess/socketcliente.o \
./DataAccess/socketserver.o 

CPP_DEPS += \
./DataAccess/docXML.d \
./DataAccess/pugixml.d \
./DataAccess/socketcliente.d \
./DataAccess/socketserver.d 


# Each subdirectory must supply rules for building sources it contributes
DataAccess/%.o: ../DataAccess/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cross G++ Compiler'
	g++ -O3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


