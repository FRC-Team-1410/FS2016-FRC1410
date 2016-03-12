################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/Subsystems/subdir.mk
-include src/Commands/Test/Test\ Shoot\ Low\ Goal\ Turn\ Commands/subdir.mk
-include src/Commands/Test/Test\ Shoot\ Low\ Goal\ Score\ Commands/subdir.mk
-include src/Commands/Test/Test\ Shoot\ Low\ Goal\ Reach\ Commands/subdir.mk
-include src/Commands/Test/Test\ Shoot\ Low\ Goal\ Prepare\ Commands/subdir.mk
-include src/Commands/Test/Test\ Shoot\ Low\ Goal\ Drive\ Commands/subdir.mk
-include src/Commands/Test/subdir.mk
-include src/Commands/Drive\ Base/subdir.mk
-include src/Commands/Climber/subdir.mk
-include src/Commands/Ball\ Manipulator/subdir.mk
-include src/Commands/Autonomous/Auto\ Shoot\ Low\ Goal/Auto\ Shoot\ Low\ Goal\ Command\ Groups/Auto\ Shoot\ Low\ Goal\ Turn\ Commands/subdir.mk
-include src/Commands/Autonomous/Auto\ Shoot\ Low\ Goal/Auto\ Shoot\ Low\ Goal\ Command\ Groups/Auto\ Shoot\ Low\ Goal\ Score\ Commands/subdir.mk
-include src/Commands/Autonomous/Auto\ Shoot\ Low\ Goal/Auto\ Shoot\ Low\ Goal\ Command\ Groups/Auto\ Shoot\ Low\ Goal\ Reach\ Commands/subdir.mk
-include src/Commands/Autonomous/Auto\ Shoot\ Low\ Goal/Auto\ Shoot\ Low\ Goal\ Command\ Groups/Auto\ Shoot\ Low\ Goal\ Prepare\ Commands/subdir.mk
-include src/Commands/Autonomous/Auto\ Shoot\ Low\ Goal/Auto\ Shoot\ Low\ Goal\ Command\ Groups/Auto\ Shoot\ Low\ Goal\ Drive\ Commands/subdir.mk
-include src/Commands/Autonomous/Auto\ Shoot\ Low\ Goal/Auto\ Shoot\ Low\ Goal\ Command\ Groups/subdir.mk
-include src/Commands/Autonomous/Auto\ Shoot\ Low\ Goal/subdir.mk
-include src/Commands/Autonomous/Auto\ Cross\ Defense/Auto\ Cross\ Defense\ Command\ Groups/Auto\ Cross\ Defense\ Drive\ Commands/subdir.mk
-include src/Commands/Autonomous/Auto\ Cross\ Defense/Auto\ Cross\ Defense\ Command\ Groups/subdir.mk
-include src/Commands/Autonomous/Auto\ Cross\ Defense/subdir.mk
-include src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: FRCUserProgram

# Tool invocations
FRCUserProgram: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GCC C++ Linker'
	g++ -L/usr/lib/x86_64-linux-gnu -LC:\Users\Ashsp/wpilib/simulation/lib -Xlinker -rpath C:\Users\Ashsp/wpilib/simulation/lib -o "FRCUserProgram" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(CC_DEPS)$(C++_DEPS)$(EXECUTABLES)$(C_UPPER_DEPS)$(CXX_DEPS)$(OBJS)$(CPP_DEPS)$(C_DEPS) FRCUserProgram
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
