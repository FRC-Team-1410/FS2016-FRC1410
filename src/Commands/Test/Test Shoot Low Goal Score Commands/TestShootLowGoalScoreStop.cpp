//Command that drives the robot to the goal
#include "TestShootLowGoalScoreStop.h"
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

TestShootLowGoalScoreStop::TestShootLowGoalScoreStop(){
	Requires(Robot::drivebase); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void TestShootLowGoalScoreStop::Initialize(){
	//This method runs only when the command is initialized
	Robot::drivebase->ResetGyro(); //Resets the gyro
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoders
}

void TestShootLowGoalScoreStop::Execute(){
	//This method runs while the command is active		//This loop runs until the robot has driven the desired amount of ticks
		//1000 ticks = 12 inches
		Robot::drivebase->DriveTank(-0.1, 0.1); //Drives straight to the goal
		Wait(0.5);
		End();
}

bool TestShootLowGoalScoreStop::IsFinished(){
	//This runs when the scheduler checks if the command is done
	//The command is always done
	//ALWAYS
	//A
	//L
	//W
	//A
	//Y
	//S
	return true;
}

void TestShootLowGoalScoreStop::End(){
	//This method is run when the command is ended
	//Nothing happens
	//Except it does stop the robot
	Robot::drivebase->DriveTank(0, 0); //Stops the robot
	Robot::drivebase->ResetEncoderPosition();
}

void TestShootLowGoalScoreStop::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
