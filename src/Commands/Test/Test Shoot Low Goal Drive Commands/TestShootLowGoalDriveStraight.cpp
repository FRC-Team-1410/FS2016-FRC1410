//Command that drives the robot forward under the low bar
#include "TestShootLowGoalDriveStraight.h"
#include "Robot.h"
#include "../../../RobotMap.h"

TestShootLowGoalDriveStraight::TestShootLowGoalDriveStraight(){
	Requires(Robot::drivebase);
	prefs = Preferences::GetInstance();
}

void TestShootLowGoalDriveStraight::Initialize(){
	Robot::drivebase->ResetGyro();
	Robot::drivebase->ResetEncoderPosition();
}

void TestShootLowGoalDriveStraight::Execute(){
	Robot::drivebase->DriveTank(-0.5, 0.5);
	Robot::drivebase->ReturnGyroPosition();
}

bool TestShootLowGoalDriveStraight::IsFinished(){
	float ticks = prefs->GetFloat("AutoShootLowGoalTicks", 14750);
	return (Robot::drivebase->ReturnEncoderDistance(0, 0, 0) >= ticks);
}

void TestShootLowGoalDriveStraight::End(){
	Robot::drivebase->ResetEncoderPosition();
	Robot::drivebase->DriveTank(0, 0);
}

void TestShootLowGoalDriveStraight::Interrupted(){
	End();
}
