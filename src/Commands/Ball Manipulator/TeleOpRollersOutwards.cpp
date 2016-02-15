#include <Commands/Ball Manipulator/TeleOpRollersOutwards.h>
#include <Commands/Ball Manipulator/TeleOpRollersInwards.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpRollersOutwards::TeleOpRollersOutwards(){
	Requires(Robot::ballmanipulator);

	prefs = Preferences::GetInstance();
	speed = prefs->GetFloat("Roller Speed", 0.5);
}

void TeleOpRollersOutwards::Initialize(){
	SmartDashboard::PutNumber("Roller Speed", 0);
	Robot::ballmanipulator->DriveIntake(0);
}

void TeleOpRollersOutwards::Execute(){
	SmartDashboard::PutNumber("Roller Speed", Robot::ballmanipulator->ReturnIntakeSpeed());
	Robot::ballmanipulator->DriveIntake(-1 * speed);
}

bool TeleOpRollersOutwards::IsFinished(){
	return false;
}

void TeleOpRollersOutwards::End(){
	SmartDashboard::PutNumber("Roller Speed", 0);
	Robot::ballmanipulator->DriveIntake(0);
}

void TeleOpRollersOutwards::Interrupted(){
	End();
}
