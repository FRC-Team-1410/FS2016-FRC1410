#include <Commands/Ball Manipulator/TeleOpRollersInwards.h>
#include <Commands/Ball Manipulator/TeleOpRollersOutwards.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpRollersInwards::TeleOpRollersInwards(){
	Requires(Robot::ballmanipulator);

	prefs = Preferences::GetInstance();
	speed = prefs->GetFloat("Roller Speed", 0.5);
}

void TeleOpRollersInwards::Initialize(){
	SmartDashboard::PutNumber("Roller Speed", 0);
	Robot::ballmanipulator->DriveIntake(0);
}

void TeleOpRollersInwards::Execute(){
	SmartDashboard::PutNumber("Roller Speed", Robot::ballmanipulator->ReturnIntakeSpeed());
	Robot::ballmanipulator->DriveIntake(speed);
}

bool TeleOpRollersInwards::IsFinished(){
	return false;
}

void TeleOpRollersInwards::End(){
	SmartDashboard::PutNumber("Roller Speed", 0);
	Robot::ballmanipulator->DriveIntake(0);
}

void TeleOpRollersInwards::Interrupted(){
	End();
}
