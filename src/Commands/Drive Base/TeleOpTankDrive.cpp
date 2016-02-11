#include <Commands/Drive Base/TeleOpTankDrive.h>
#include "Robot.h"
#include "../../RobotMap.h"

TeleOpTankDrive::TeleOpTankDrive(){
	Requires(Robot::drivebase);
	Robot::drivebase->CalibrateGyro();
}

void TeleOpTankDrive::Initialize(){
	Robot::drivebase->ResetGyro();
}

void TeleOpTankDrive::Execute(){
	Robot::drivebase->DriveExponential(Robot::oi->GetDriveAxis(tankLeftAxis), -1 * Robot::oi->GetDriveAxis(tankRightAxis));
	SmartDashboard::PutNumber("Left Speed", Robot::oi->GetDriveAxis(tankLeftAxis));
	SmartDashboard::PutNumber("Right Speed", Robot::oi->GetDriveAxis(tankRightAxis));
	Robot::drivebase->ReturnGyroPosition();
}

bool TeleOpTankDrive::IsFinished(){
	return false;
}

void TeleOpTankDrive::End(){
	SmartDashboard::PutNumber("Left Speed", 0);
	SmartDashboard::PutNumber("Right Speed", 0);
	Robot::drivebase->DriveExponential(0, 0);
	Robot::drivebase->ResetGyro();
}

void TeleOpTankDrive::Interrupted(){
	End();
}
