################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/Commands/Ball\ Manipulator/TeleOpMoveArm.cpp \
../src/Commands/Ball\ Manipulator/TeleOpRollersInwards.cpp \
../src/Commands/Ball\ Manipulator/TeleOpRollersOutwards.cpp 

OBJS += \
./src/Commands/Ball\ Manipulator/TeleOpMoveArm.o \
./src/Commands/Ball\ Manipulator/TeleOpRollersInwards.o \
./src/Commands/Ball\ Manipulator/TeleOpRollersOutwards.o 

CPP_DEPS += \
./src/Commands/Ball\ Manipulator/TeleOpMoveArm.d \
./src/Commands/Ball\ Manipulator/TeleOpRollersInwards.d \
./src/Commands/Ball\ Manipulator/TeleOpRollersOutwards.d 


# Each subdirectory must supply rules for building sources it contributes
src/Commands/Ball\ Manipulator/TeleOpMoveArm.o: ../src/Commands/Ball\ Manipulator/TeleOpMoveArm.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Commands/Ball Manipulator/TeleOpMoveArm.d" -MT"src/Commands/Ball\ Manipulator/TeleOpMoveArm.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Commands/Ball\ Manipulator/TeleOpRollersInwards.o: ../src/Commands/Ball\ Manipulator/TeleOpRollersInwards.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Commands/Ball Manipulator/TeleOpRollersInwards.d" -MT"src/Commands/Ball\ Manipulator/TeleOpRollersInwards.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

src/Commands/Ball\ Manipulator/TeleOpRollersOutwards.o: ../src/Commands/Ball\ Manipulator/TeleOpRollersOutwards.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -std=c++11 -I"C:\Users\Ashsp\Documents\GitHub\FS2016-FRC1410/src" -IC:\Users\Ashsp/wpilib/simulation/include -I/usr/include -I/usr/include/gazebo-6.5 -I/usr/include/ignition/math2 -I/usr/include/sdformat-3.7 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"src/Commands/Ball Manipulator/TeleOpRollersOutwards.d" -MT"src/Commands/Ball\ Manipulator/TeleOpRollersOutwards.d" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


