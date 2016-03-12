################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Climber/TeleOpActuateServo.cpp \
../src/Commands/Climber/TeleOpClimb.cpp \
../src/Commands/Climber/TeleOpRotateClimber.cpp \
../src/Commands/Climber/TeleOpWinchClimber.cpp 

OBJS += \
./src/Commands/Climber/TeleOpActuateServo.o \
./src/Commands/Climber/TeleOpClimb.o \
./src/Commands/Climber/TeleOpRotateClimber.o \
./src/Commands/Climber/TeleOpWinchClimber.o 

CPP_DEPS += \
./src/Commands/Climber/TeleOpActuateServo.d \
./src/Commands/Climber/TeleOpClimb.d \
./src/Commands/Climber/TeleOpRotateClimber.d \
./src/Commands/Climber/TeleOpWinchClimber.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Climber/%.o: ../src/Commands/Climber/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


