################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreRollers.cpp \
../src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreStop.cpp 

OBJS += \
./src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreRollers.o \
./src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreStop.o 

CPP_DEPS += \
./src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreRollers.d \
./src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreStop.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreRollers.o: ../src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreRollers.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Commands/Test/Test Shoot Low Goal Score Commands/TestShootLowGoalScoreRollers.d" -MT"src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreRollers.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreStop.o: ../src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreStop.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Commands/Test/Test Shoot Low Goal Score Commands/TestShootLowGoalScoreStop.d" -MT"src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/TestShootLowGoalScoreStop.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


