#include <Commands/Defense Manipulator/TeleOpMoveManipulator.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpMoveManipulator::TeleOpMoveManipulator(){
	Requires(Robot::defensemanipulator);
}

void TeleOpMoveManipulator::Initialize(){

}

void TeleOpMoveManipulator::Execute(){
	Robot::defensemanipulator->RotateManipulator(Robot::oi->GetOperatorAxis(defenseManipulatorMovement));
}

bool TeleOpMoveManipulator::IsFinished(){
	return false;
}

void TeleOpMoveManipulator::End(){
	Robot::defensemanipulator->RotateManipulator(0);
}

void TeleOpMoveManipulator::Interrupted(){
	End();
}
