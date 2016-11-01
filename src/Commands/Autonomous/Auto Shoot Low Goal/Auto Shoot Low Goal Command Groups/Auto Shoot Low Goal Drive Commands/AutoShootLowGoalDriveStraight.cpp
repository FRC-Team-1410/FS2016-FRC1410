//Command that drives the robot forward under the low bar
#include "AutoShootLowGoalDriveStraight.h"
#include "Robot.h"
#include "../../../../../RobotMap.h"

AutoShootLowGoalDriveStraight::AutoShootLowGoalDriveStraight(){
	Requires(Robot::drivebase);
	prefs = Preferences::GetInstance();
}

void AutoShootLowGoalDriveStraight::Initialize(){
	Robot::drivebase->ResetGyro();
	Robot::drivebase->ResetEncoderPosition();
}

void AutoShootLowGoalDriveStraight::Execute(){
	float speed = prefs->GetFloat("AutoShootLowGoalDriveSpeed", 0.6);
	Robot::drivebase->DriveTank(-speed, speed);
	Robot::drivebase->ReturnGyroPosition();
}

bool AutoShootLowGoalDriveStraight::IsFinished(){
	float ticks = prefs->GetFloat("AutoShootLowGoalTicks", 19500);
	return (Robot::drivebase->ReturnEncoderDistance(0, 0, 0) >= ticks);
}

void AutoShootLowGoalDriveStraight::End(){
	Robot::drivebase->ResetEncoderPosition();
	Robot::drivebase->DriveTank(0, 0);
}

void AutoShootLowGoalDriveStraight::Interrupted(){
	End();
}
