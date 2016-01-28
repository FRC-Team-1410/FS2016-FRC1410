#include <Commands/Ball Manipulator/TeleOpMoveIntake.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpMoveIntake::TeleOpMoveIntake(){
	Requires(Robot::ballmanipulator);
	up_limit = Robot::ballmanipulator->ReturnUpLimit();
	down_limit = Robot::ballmanipulator->ReturnDownLimit();
}

void TeleOpMoveIntake::Initialize(){
	up_limit = Robot::ballmanipulator->ReturnUpLimit();
	down_limit = Robot::ballmanipulator->ReturnDownLimit();
}

void TeleOpMoveIntake::Execute(){
	up_limit = Robot::ballmanipulator->ReturnUpLimit();
	down_limit = Robot::ballmanipulator->ReturnDownLimit();

	if(up_limit && Robot::oi->GetOperatorAxis(ballManipulatorMovement) <= 0){
		Robot::ballmanipulator->RotateManipulator(Robot::oi->GetOperatorAxis(ballManipulatorMovement));
	}
	else if(down_limit && Robot::oi->GetOperatorAxis(ballManipulatorMovement) >= 0){
		Robot::ballmanipulator->RotateManipulator(Robot::oi->GetOperatorAxis(ballManipulatorMovement));
	}
	else{
		Robot::ballmanipulator->RotateManipulator(Robot::oi->GetOperatorAxis(ballManipulatorMovement));
	}
}

bool TeleOpMoveIntake::IsFinished(){
	up_limit = Robot::ballmanipulator->ReturnUpLimit();
	down_limit = Robot::ballmanipulator->ReturnDownLimit();

	if(Robot::oi->GetOperatorAxis(ballManipulatorMovement) <= 0){
		return Robot::ballmanipulator->ReturnDownLimit();
	}
	else if(Robot::oi->GetOperatorAxis(ballManipulatorMovement) >= 0){
		return Robot::ballmanipulator->ReturnUpLimit();
	}
	else{
		return false;
	}
}

void TeleOpMoveIntake::End(){
	up_limit = Robot::ballmanipulator->ReturnUpLimit();
	down_limit = Robot::ballmanipulator->ReturnDownLimit();
	Robot::ballmanipulator->RotateManipulator(0);
}

void TeleOpMoveIntake::Interrupted(){
	End();
}
