################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Subsystems/BallManipulator.cpp \
../src/Subsystems/Climber.cpp \
../src/Subsystems/DriveBase.cpp 

OBJS += \
./src/Subsystems/BallManipulator.o \
./src/Subsystems/Climber.o \
./src/Subsystems/DriveBase.o 

CPP_DEPS += \
./src/Subsystems/BallManipulator.d \
./src/Subsystems/Climber.d \
./src/Subsystems/DriveBase.d 


# Each subdirectory must supply rules for building sources it contributes
src/Subsystems/%.o: ../src/Subsystems/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


