#include <Commands/Climber/TeleOpWinchClimber.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpWinchClimber::TeleOpWinchClimber(float speed){
	Requires(Robot::climber);

	prefs = Preferences::GetInstance();
	climber_speed = speed;
}

void TeleOpWinchClimber::Initialize(){

}

void TeleOpWinchClimber::Execute(){
	Robot::climber->WinchClimber(climber_speed);
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
