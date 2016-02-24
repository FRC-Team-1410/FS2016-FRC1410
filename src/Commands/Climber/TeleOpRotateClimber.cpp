//This command rotates the climber
//It takes the value from the y-axis on the logitech joystick we have
#include <Commands/Climber/TeleOpRotateClimber.h> //Includes the header file for this class
#include "Robot.h" //Includes Robot.h so the OI methods can be used
#include "../../RobotMap.h" //Includes RobotMap.h for all the constants that are stored in there

TeleOpRotateClimber::TeleOpRotateClimber(){
	prefs = Preferences::GetInstance(); //Initializes the prefs object in this class

	Requires(Robot::climber); //Requires the climber subsystem
}

void TeleOpRotateClimber::Initialize(){
	//Nothing happens when this command is initialized
}

void TeleOpRotateClimber::Execute(){
	//This method runs while the command is being called
	//The while loop is here so that the climber does not move if either the upper or lower limit is triggered
	//If neither the upper or lower limit is triggered, the climber is rotated through values recieved from the y axis on the logitech controller
	if(!Robot::climber->ReturnDownLimit() || !Robot::climber->ReturnUpLimit()){
		Robot::climber->RotateClimber(Robot::oi->GetClimberAxis(climberRotationAxis));
	}
}

bool TeleOpRotateClimber::IsFinished(){
	//This method returns true if either limit switch is triggered
	return Robot::climber->ReturnDownLimit() || Robot::climber->ReturnUpLimit(); //Returns if either limit switch is triggered
}

void TeleOpRotateClimber::End(){
	//This method runs when the command is ended
	//Stops the climber
	Robot::climber->RotateClimber(0); //Sets the speed of the climber to 0
}

void TeleOpRotateClimber::Interrupted(){
	//This runs when the command is interrupted
	//It just ends the command
	End(); //Ends the command
}
