################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Autonomous/Auto\ Cross\ Defense/Auto\ Cross\ Defense\ Command\ Groups/AutoCrossDefenseDrive.cpp 

OBJS += \
./src/Commands/Autonomous/Auto\ Cross\ Defense/Auto\ Cross\ Defense\ Command\ Groups/AutoCrossDefenseDrive.o 

CPP_DEPS += \
./src/Commands/Autonomous/Auto\ Cross\ Defense/Auto\ Cross\ Defense\ Command\ Groups/AutoCrossDefenseDrive.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Autonomous/Auto\ Cross\ Defense/Auto\ Cross\ Defense\ Command\ Groups/AutoCrossDefenseDrive.o: ../src/Commands/Autonomous/Auto\ Cross\ Defense/Auto\ Cross\ Defense\ Command\ Groups/AutoCrossDefenseDrive.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Commands/Autonomous/Auto Cross Defense/Auto Cross Defense Command Groups/AutoCrossDefenseDrive.d" -MT"src/Commands/Autonomous/Auto\ Cross\ Defense/Auto\ Cross\ Defense\ Command\ Groups/AutoCrossDefenseDrive.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


