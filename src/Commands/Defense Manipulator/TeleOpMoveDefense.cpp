#include <Commands/Defense Manipulator/TeleOpMoveDefense.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpMoveDefense::TeleOpMoveDefense(){
	Requires(Robot::defensemanipulator);
	up_limit = Robot::defensemanipulator->ReturnUpLimit();
	down_limit = Robot::defensemanipulator->ReturnDownLimit();
}

void TeleOpMoveDefense::Initialize(){
	up_limit = Robot::defensemanipulator->ReturnUpLimit();
	down_limit = Robot::defensemanipulator->ReturnDownLimit();
}

void TeleOpMoveDefense::Execute(){
	up_limit = Robot::defensemanipulator->ReturnUpLimit();
	down_limit = Robot::defensemanipulator->ReturnDownLimit();

	if(up_limit && Robot::oi->GetOperatorAxis(ballManipulatorMovement) <= 0){
		Robot::defensemanipulator->RotateManipulator(Robot::oi->GetOperatorAxis(ballManipulatorMovement));
	}
	else if(down_limit && Robot::oi->GetOperatorAxis(ballManipulatorMovement) >= 0){
		Robot::defensemanipulator->RotateManipulator(Robot::oi->GetOperatorAxis(ballManipulatorMovement));
	}
	else{
		Robot::defensemanipulator->RotateManipulator(Robot::oi->GetOperatorAxis(ballManipulatorMovement));
	}
}

bool TeleOpMoveDefense::IsFinished(){
	up_limit = Robot::defensemanipulator->ReturnUpLimit();
		down_limit = Robot::defensemanipulator->ReturnDownLimit();

		if(Robot::oi->GetOperatorAxis(ballManipulatorMovement) <= 0){
			return Robot::defensemanipulator->ReturnDownLimit();
		}
		else if(Robot::oi->GetOperatorAxis(ballManipulatorMovement) >= 0){
			return Robot::defensemanipulator->ReturnUpLimit();
		}
		else{
			return false;
		}
}

void TeleOpMoveDefense::End(){
	up_limit = Robot::defensemanipulator->ReturnUpLimit();
	down_limit = Robot::defensemanipulator->ReturnDownLimit();
	Robot::defensemanipulator->RotateManipulator(0);
}

void TeleOpMoveDefense::Interrupted(){
	End();
}
