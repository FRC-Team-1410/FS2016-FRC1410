//This command is what we use to output the ball
//All it does is run the rollers in a positive direction
#include <Commands/Ball Manipulator/TeleOpRollersOutwards.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpRollersOutwards::TeleOpRollersOutwards(){
	Requires(Robot::ballmanipulator); //Requires the ballmanipulator subsystem
	SetInterruptible(true); //Says the command can be interrupted (not sure if this is needed)

	prefs = Preferences::GetInstance(); //Initializes the prefs object in this class
	speed = prefs->GetFloat("RollerSpeed", 0.5); //Sets speed to the value retrieved from the SmartDashboard (default is 0.5)
}

void TeleOpRollersOutwards::Initialize(){
	//Whenever the command is initialized it will retrieve the speed needed to be used
	speed = prefs->GetFloat("Roller Speed", 0.5); //Sets speed to the value retrieved from the SmartDashboard (default is 0.5)
}

void TeleOpRollersOutwards::Execute(){
	//This method runs while the command is being called
	//All it does is set the rollers to the speed from SmartDashboard
	Robot::ballmanipulator->SetRollers(speed * -1); //Sets the speed of the rollers to speed
}

bool TeleOpRollersOutwards::IsFinished(){
	//We only end the command when the button is pressed so it never returns true here
	return false; //Returns false
}

void TeleOpRollersOutwards::End(){
	//This ends the command
	//It just sets the rollers to 0
	//This is so that the rollers aren't always running
	Robot::ballmanipulator->SetRollers(0); //Sets the roller speed to 0
}

void TeleOpRollersOutwards::Interrupted(){
	//This command is interrupted (hopefully) when TeleOpRollerInwards is called
	//Thus, it ends the command
	End(); //Ends the command
}
