//Command that drives the robot to the goal
#include "TestShootLowGoalReachDrive.h"
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

TestShootLowGoalReachDrive::TestShootLowGoalReachDrive(){
	Requires(Robot::drivebase); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void TestShootLowGoalReachDrive::Initialize(){
	//This method runs only when the command is initialized
	Robot::drivebase->ResetGyro(); //Resets the gyro
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoders
}

void TestShootLowGoalReachDrive::Execute(){
	//This method runs while the command is active		//This loop runs until the robot has driven the desired amount of ticks
	float speed = prefs->GetFloat("AutoShootLowGoalDriveSpeed", 0.6);
	Robot::drivebase->DriveTank(-speed, speed); //Drives straight to the goal
}

bool TestShootLowGoalReachDrive::IsFinished(){
	//This runs when the scheduler checks if the command is done
	//The command is always done
	//ALWAYS
	//A
	//L
	//W
	//A
	//Y
	//S
	float ticks = prefs->GetFloat("AutoShootLowGoalReachTicks", 10300); //Retrieves the ticks to be driven from the SmartDashboard
	return (Robot::drivebase->ReturnEncoderDistance(0, 0, 0) >= ticks); //Returns true
}

void TestShootLowGoalReachDrive::End(){
	//This method is run when the command is ended
	//Nothing happens
	//Except it does stop the robot
	Robot::drivebase->DriveTank(0, 0); //Stops the robot
	Robot::drivebase->ResetEncoderPosition();
}

void TestShootLowGoalReachDrive::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
