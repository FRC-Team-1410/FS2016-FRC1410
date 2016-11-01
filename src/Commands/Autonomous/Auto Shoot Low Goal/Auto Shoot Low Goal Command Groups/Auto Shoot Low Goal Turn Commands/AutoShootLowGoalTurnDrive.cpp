//Command that turns the robot to drive to the goal
#include "AutoShootLowGoalTurnDrive.h" //Includes the header file for this class
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

AutoShootLowGoalTurnDrive::AutoShootLowGoalTurnDrive(){
	Requires(Robot::drivebase); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void AutoShootLowGoalTurnDrive::Initialize(){
	//This method runs only when the command is initialized
	Robot::drivebase->ResetGyro(); //Resets the gyro
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoders
}

void AutoShootLowGoalTurnDrive::Execute(){
	//This method runs while the command is active
	float speed = prefs->GetFloat("AutoShootLowGoalDriveSpeed", 0.6);
	Robot::drivebase->DriveTank(-speed, -speed); //Turns to the right
}

bool AutoShootLowGoalTurnDrive::IsFinished(){
	float angle = prefs->GetFloat("AutoShootLowGoalTurnAngle", 60); //Retrieves the angle to be driven from the SmartDashboard
	return Robot::drivebase->ReturnGyroPosition() >= angle; //Returns true
}

void AutoShootLowGoalTurnDrive::End(){
	//This method is run when the command is ended
	//Nothing happens
	//Except it does stop the robot
	Robot::drivebase->DriveTank(0, 0); //Stops the robot
}

void AutoShootLowGoalTurnDrive::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
