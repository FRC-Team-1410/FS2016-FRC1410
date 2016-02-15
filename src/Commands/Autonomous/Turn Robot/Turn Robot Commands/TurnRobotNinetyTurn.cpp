#include <Commands/Autonomous/Turn Robot/Turn Robot Commands/TurnRobotNinetyTurn.h>
#include "Robot.h"
#include "../../../../RobotMap.h"

TurnRobotNinetyTurn::TurnRobotNinetyTurn(){
	Requires(Robot::drivebase);
	prefs = Preferences::GetInstance();
}

void TurnRobotNinetyTurn::Initialize(){
	Robot::drivebase->ResetGyro();
	Robot::drivebase->ResetEncoderPosition();
}

void TurnRobotNinetyTurn::Execute(){
	float angle = prefs->GetFloat("TurnAngle", 90);
	while(Robot::drivebase->ReturnGyroPosition() <= angle){
		Robot::drivebase->DriveTank(-0.5, -0.5);
	}
	//Robot::drivebase->DriveStraight(0.5);
	//Wait(0.5);
	End();
}

bool TurnRobotNinetyTurn::IsFinished(){
	return true;
}

void TurnRobotNinetyTurn::End(){
	Robot::drivebase->DriveTank(0, 0);
}

void TurnRobotNinetyTurn::Interrupted(){
	End();
}
