#include <Commands/Climber/TeleOpToggleClimber.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpToggleClimber::TeleOpToggleClimber(){
	prefs = Preferences::GetInstance();

	Requires(Robot::drivebase);

	speed = prefs->GetFloat("Climber Speed", 0.5);
	move_up = true;
}

void TeleOpToggleClimber::Initialize(){
	move_up = !move_up;
}

void TeleOpToggleClimber::Execute(){
	if(move_up){
		if(Robot::climber->ReturnUpLimit() == false){
			Robot::climber->RotateClimber(speed);
		}
	}

	else{
		if(Robot::climber->ReturnDownLimit() == false){
			Robot::climber->RotateClimber(-1 * speed);
		}
	}
}

bool TeleOpToggleClimber::IsFinished(){
	if(move_up){
		return Robot::climber->ReturnUpLimit();
	}
	else{
		return Robot::climber->ReturnDownLimit();
	}
}

void TeleOpToggleClimber::End(){
	Robot::climber->RotateClimber(0);
}

void TeleOpToggleClimber::Interrupted(){
	End();
}
