#include <Commands/Autonomous/Test Auto/Test Auto Commands/TestAutoDriveStraight.h>
#include "Robot.h"
#include "../../../../RobotMap.h"

TestAutoDriveStraight::TestAutoDriveStraight(){
	Requires(Robot::drivebase);
	angle = 0;
	deviation = 0;
	left_speed = 0.5;
	right_speed = 0.5;
}

void TestAutoDriveStraight::Initialize(){
	Robot::drivebase->ResetGyro();
}

void TestAutoDriveStraight::Execute(){
	angle = Robot::drivebase->ReturnGyroPosition();
	deviation = angle / 180;
	SmartDashboard::PutNumber("Deviation Percentage", deviation);
	left_speed = (1 + deviation) * 0.5;
	right_speed = (-1 + deviation) * 0.5;
	Robot::drivebase->DriveTank(left_speed, right_speed);
}

bool TestAutoDriveStraight::IsFinished(){
	return false;
}

void TestAutoDriveStraight::End(){
	Robot::drivebase->ResetGyro();
}

void TestAutoDriveStraight::Interrupted(){
	End();
}
