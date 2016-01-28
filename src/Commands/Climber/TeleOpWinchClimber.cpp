#include <Commands/Climber/TeleOpWinchClimber.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpWinchClimber::TeleOpWinchClimber(){
	Requires(Robot::climber);

	prefs = Preferences::GetInstance();
	speed = prefs->GetFloat("Winch Speed", 0.5);
}

void TeleOpWinchClimber::Initialize(){

}

void TeleOpWinchClimber::Execute(){
	Robot::climber->WinchClimber(speed);
}

bool TeleOpWinchClimber::IsFinished(){
	return false;
}

void TeleOpWinchClimber::End(){
	Robot::climber->WinchClimber(0);
}

void TeleOpWinchClimber::Interrupted(){
	End();
}
