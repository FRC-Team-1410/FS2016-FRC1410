################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Test/TestShootLowGoalDrive.cpp \
../src/Commands/Test/TestShootLowGoalPrepare.cpp \
../src/Commands/Test/TestShootLowGoalReach.cpp \
../src/Commands/Test/TestShootLowGoalScore.cpp \
../src/Commands/Test/TestShootLowGoalTurn.cpp 

OBJS += \
./src/Commands/Test/TestShootLowGoalDrive.o \
./src/Commands/Test/TestShootLowGoalPrepare.o \
./src/Commands/Test/TestShootLowGoalReach.o \
./src/Commands/Test/TestShootLowGoalScore.o \
./src/Commands/Test/TestShootLowGoalTurn.o 

CPP_DEPS += \
./src/Commands/Test/TestShootLowGoalDrive.d \
./src/Commands/Test/TestShootLowGoalPrepare.d \
./src/Commands/Test/TestShootLowGoalReach.d \
./src/Commands/Test/TestShootLowGoalScore.d \
./src/Commands/Test/TestShootLowGoalTurn.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Test/%.o: ../src/Commands/Test/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


