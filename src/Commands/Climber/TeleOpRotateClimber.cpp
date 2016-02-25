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
	//It sets the rotation of the climber to the value of GetClimberAxis
	Robot::climber->RotateClimber(Robot::oi->GetClimberAxis(climberRotationAxis)); //Sets the rotation of the climber to the value from the oi

}

bool TeleOpRotateClimber::IsFinished(){
	//This method returns if the command is finished
	if(Robot::oi->GetClimberAxis(climberRotationAxis) > 0){
		//This is returned if the climber is rotating down
		return Robot::climber->ReturnDownLimit(); //Returns if the lower limit is triggered
	}
	else if(Robot::oi->GetClimberAxis(climberRotationAxis) < 0){
		//This returns if the climber is rotating up
		return Robot::climber->ReturnUpLimit(); //Returns if the upper limit is triggered
	}
	else{
		//This only runs as the default
		return false; //Returns false if neither of the above conditions is correct
	}
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
