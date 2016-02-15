#include <Commands/Camera/TeleOpMoveCamera.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpMoveCamera::TeleOpMoveCamera(){
	Requires(Robot::drivebase);
}

void TeleOpMoveCamera::Initialize(){

}

void TeleOpMoveCamera::Execute(){
	Robot::camera->MoveCamera(Robot::oi->GetOperatorAxis(0), Robot::oi->GetOperatorAxis(1));
}

bool TeleOpMoveCamera::IsFinished(){
	return false;
}

void TeleOpMoveCamera::End(){

}

void TeleOpMoveCamera::Interrupted(){
	End();
}
