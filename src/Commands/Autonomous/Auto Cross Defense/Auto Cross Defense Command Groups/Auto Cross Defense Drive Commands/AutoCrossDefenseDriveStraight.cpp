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
	Robot::drivebase->DriveTank(-0.5, 0.5);
	Robot::drivebase->ReturnGyroPosition();
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
	float ticks = prefs->GetFloat("AutoCrossDefenseTicks", 15000);
	return (Robot::drivebase->ReturnEncoderDistance(0, 0, 0) >= ticks); //Returns true
}

void AutoCrossDefenseDriveStraight::End(){
	//This method is run when the command is ended
	//It just cleans up
	//Robot::drivebase->ResetEncoderPosition(); //Resets the encoder position
	Robot::drivebase->DriveTank(0, 0);
}

void AutoCrossDefenseDriveStraight::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
