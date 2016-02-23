#include <Commands/Climber/TeleOpToggleClimber.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpToggleClimber::TeleOpToggleClimber(){
	prefs = Preferences::GetInstance();

	Requires(Robot::drivebase);

	speed = prefs->GetFloat("RotateSpeed", 1);
	move_up = true;
}

void TeleOpToggleClimber::Initialize(){
	//move_up = !move_up;
}

void TeleOpToggleClimber::Execute(){
	/**if(move_up){
		if(Robot::climber->ReturnUpLimit() == false){
			Robot::climber->RotateClimber(speed);
		}
	}

	else{
		if(Robot::climber->ReturnDownLimit() == false){
			Robot::climber->RotateClimber(-1 * speed);
		}
	}**/
	Robot::climber->RotateClimber(Robot::oi->GetClimberAxis(climberRotationAxis) * speed);
}

bool TeleOpToggleClimber::IsFinished(){
	return false;
}

void TeleOpToggleClimber::End(){
	Robot::climber->RotateClimber(0);
}

void TeleOpToggleClimber::Interrupted(){
	End();
}
