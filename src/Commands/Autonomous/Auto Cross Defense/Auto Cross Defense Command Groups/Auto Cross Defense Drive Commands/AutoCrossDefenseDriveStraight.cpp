//This is the default Autonomous command
//It literally drives forward 15000 ticks or about 15 feet
//It does this by using the encoders
//It also returns the gyro angle for testing purposes
#include "AutoCrossDefenseDriveStraight.h" //Includes the header file for this class
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

AutoCrossDefenseDriveStraight::AutoCrossDefenseDriveStraight(){
	Requires(Robot::drivebase); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void AutoCrossDefenseDriveStraight::Initialize(){
	//This method runs only when the command is initialized
	Robot::drivebase->ResetGyro(); //Resets the gyro
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoders
}

void AutoCrossDefenseDriveStraight::Execute(){
	//This method runs while the command is active
	float ticks = prefs->GetFloat("AutoCrossDefenseTicks", 15000); //Retrieves the amount of ticks to be driven from the SmartDashboard
	while(Robot::drivebase->ReturnEncoderDistance(0,0,0) <= 15000){
		//This loop runs until the amount of ticks driven is equal to the amount of ticks desired
		//1000 ticks is equal to about one foot of driving
		Robot::drivebase->DriveTank(-0.5, 0.5); //Drives straight
		Robot::drivebase->ReturnGyroPosition(); //Returns the angle from the gyro
	}
	End(); //Ends the command when the robot has driven the desired amount of ticks
}

bool AutoCrossDefenseDriveStraight::IsFinished(){
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

void AutoCrossDefenseDriveStraight::End(){
	//This method is run when the command is ended
	//It just cleans up
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoder position
}

void AutoCrossDefenseDriveStraight::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
