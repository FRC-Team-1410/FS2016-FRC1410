//Command that drives the robot to the goal
#include "AutoShootLowGoalReachDrive.h" //Includes the header file for this class
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

AutoShootLowGoalReachDrive::AutoShootLowGoalReachDrive(){
	Requires(Robot::drivebase); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void AutoShootLowGoalReachDrive::Initialize(){
	//This method runs only when the command is initialized
	Robot::drivebase->ResetGyro(); //Resets the gyro
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoders
}

void AutoShootLowGoalReachDrive::Execute(){
	//This method runs while the command is active		//This loop runs until the robot has driven the desired amount of ticks
	float speed = prefs->GetFloat("AutoShootLowGoalDriveSpeed", 0.6);
	Robot::drivebase->DriveTank(-speed, speed); //Drives straight to the goal
}

bool AutoShootLowGoalReachDrive::IsFinished(){
	//This runs when the scheduler checks if the command is done
	//The command is always done
	//ALWAYS
	//A
	//L
	//W
	//A
	//Y
	//S
	float ticks = prefs->GetFloat("AutoShootLowGoalReachTicks", 10500); //Retrieves the ticks to be driven from the SmartDashboard
	return (Robot::drivebase->ReturnEncoderDistance(0, 0, 0) >= ticks); //Returns true
}

void AutoShootLowGoalReachDrive::End(){
	//This method is run when the command is ended
	//Nothing happens
	//Except it does stop the robot
	Robot::drivebase->DriveTank(0, 0); //Stops the robot
	Robot::drivebase->ResetEncoderPosition();
}

void AutoShootLowGoalReachDrive::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
