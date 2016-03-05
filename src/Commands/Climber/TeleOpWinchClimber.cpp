//This is the command that drives the winch
//It is called three times by three different buttons
//One button winches in
//One button winches out
//One button winches with a value of 0
//The third button is so we can rotate the climber without winching at all
//Because of the three uses there is a float speed in the constructor
//Otherwise it is just a simple command that runs
#include <Commands/Climber/TeleOpWinchClimber.h> //Includes the header file for this class
#include "Robot.h" //Includes Robot.h so that the OI methods can be used
#include "../../RobotMap.h" //Includes RobotMap.h for all the constants stored there

TeleOpWinchClimber::TeleOpWinchClimber(float speed){
	Requires(Robot::climber); //Requires the climber class

	prefs = Preferences::GetInstance(); //Initializes the prefs object in this class
	climber_speed = speed; //Retrieves the speed value from the constructor and puts it into climber_speed
}

void TeleOpWinchClimber::Initialize(){
	float unlock_position = prefs->GetFloat("ClimberUnlockPosition", 0.65);
	Robot::climber->MoveServo(unlock_position); //Unlocks the winch
}

void TeleOpWinchClimber::Execute(){
	//This method runs while the command is being called
	Robot::climber->WinchClimber(climber_speed); //Winches the climber at the speed put into the constructor
}

bool TeleOpWinchClimber::IsFinished(){
	//We end the command when the button is released
	//But also when the limit switch is triggered
	//So the method returns if the limit switch is closed
	return Robot::climber->ReturnWinchLimit(); //Returns if the winch's limit switch is triggered
}

void TeleOpWinchClimber::End(){
	//This runs when the command is ended
	//It basically stops the winch
	float lock_position = prefs->GetFloat("ClimberLockPosition", 0.35);
	Robot::climber->WinchClimber(0); //This sets the winch to 0
	Robot::climber->MoveServo(lock_position); //Locks the winch when the command is done
}

void TeleOpWinchClimber::Interrupted(){
	//This method runs when the command is interrupted
	//It literally just ends the command
	End(); //Ends the command
}
