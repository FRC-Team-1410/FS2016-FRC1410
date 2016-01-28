#include <Commands/Ball Manipulator/TeleOpToggleRollers.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpToggleRollers::TeleOpToggleRollers(){
	Requires(Robot::ballmanipulator);

	prefs = Preferences::GetInstance();
	speed = prefs->GetFloat("Roller Speed", 0.5);
}

void TeleOpToggleRollers::Initialize(){

}

void TeleOpToggleRollers::Execute(){
	Robot::ballmanipulator->DriveIntake(speed);
}

bool TeleOpToggleRollers::IsFinished(){
	return false;
}

void TeleOpToggleRollers::End(){

}

void TeleOpToggleRollers::Interrupted(){
	End();
}
