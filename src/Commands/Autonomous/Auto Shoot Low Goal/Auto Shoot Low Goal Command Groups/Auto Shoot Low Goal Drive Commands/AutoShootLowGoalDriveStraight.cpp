//Command that drives the robot forward under the low bar
#include "AutoShootLowGoalDriveStraight.h" //Includes the header file for this class
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

AutoShootLowGoalDriveStraight::AutoShootLowGoalDriveStraight(){
	Requires(Robot::drivebase); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void AutoShootLowGoalDriveStraight::Initialize(){
	//This method runs only when the command is initialized
	Robot::drivebase->ResetGyro(); //Resets the gyro
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoders
}

void AutoShootLowGoalDriveStraight::Execute(){
	//This method runs while the command is active
	float ticks = prefs->GetFloat("AutoShootLowGoalTicks", 16583); //Retrieves the amount of ticks to be driven from the SmartDashboard
	while(Robot::drivebase->ReturnEncoderDistance(0,0,0) <= ticks){
		//This loop runs until the amount of ticks driven is equal to the amount of ticks desired
		//1000 ticks is equal to about one foot of driving
		Robot::drivebase->DriveTank(-0.5, 0.5); //Drives straight
		Robot::drivebase->ReturnGyroPosition(); //Returns the angle from the gyro
	}
	End(); //Ends the command when the robot has driven the desired amount of ticks
}

bool AutoShootLowGoalDriveStraight::IsFinished(){
	//This runs when the scheduler checks if the command is done
	//The command is always done
	//ALWAYS
	//A
	//L
	//W
	//A
	//Y
	//S
	return true; //Returns true
}

void AutoShootLowGoalDriveStraight::End(){
	//This method is run when the command is ended
	//It just cleans up
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoder position
	//And stops the robot from driving more
	Robot::drivebase->DriveTank(0, 0); //Stops the robot
}

void AutoShootLowGoalDriveStraight::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
