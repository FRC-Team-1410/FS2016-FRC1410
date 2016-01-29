#include <Commands/Autonomous/Test Auto/Test Auto Commands/TestAutoDriveStraight.h>
#include "Robot.h"
#include "../../../../RobotMap.h"

TestAutoDriveStraight::TestAutoDriveStraight(){
	Requires(Robot::drivebase);
	angle = 0;
}

void TestAutoDriveStraight::Initialize(){
	Robot::drivebase->ResetGyro();
}

void TestAutoDriveStraight::Execute(){
	angle = Robot::drivebase->ReturnGyroPosition();
	SmartDashboard::PutNumber("Gyro Angle", angle);
	float deviation = angle / 180;
	SmartDashboard::PutNumber("Deviation Percentage", deviation);
	float left_speed = (1 + deviation) * 0.5;
	SmartDashboard::PutNumber("Left Speed", left_speed);
	float right_speed = (-1 + deviation) * 0.5;
	SmartDashboard::PutNumber("Right Speed", right_speed * -1);
	Robot::drivebase->DriveTank(left_speed, right_speed);
}

bool TestAutoDriveStraight::IsFinished(){
	return false;
}

void TestAutoDriveStraight::End(){

}

void TestAutoDriveStraight::Interrupted(){
	End();
}
