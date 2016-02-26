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
	float angle = prefs->GetFloat("AutoShootLowGoalAngle", 28.359); //Retrieves the angle to be driven from the SmartDashboard
	while(Robot::drivebase->ReturnGyroPosition() <= angle){
		//This loop runs until the robot has turned to the angle desired
		//The angle is in degrees
		Robot::drivebase->DriveTank(-0.5, -0.5); //Turns to the right
	}
	End(); //Ends the command when the robot has turned to the expected angle
}

bool AutoShootLowGoalTurnDrive::IsFinished(){
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
