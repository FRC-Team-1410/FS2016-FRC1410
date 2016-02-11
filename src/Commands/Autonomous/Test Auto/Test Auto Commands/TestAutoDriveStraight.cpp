#include <Commands/Autonomous/Test Auto/Test Auto Commands/TestAutoDriveStraight.h>
#include "Robot.h"
#include "../../../../RobotMap.h"

TestAutoDriveStraight::TestAutoDriveStraight(){
	Requires(Robot::drivebase);
	prefs = Preferences::GetInstance();
}

void TestAutoDriveStraight::Initialize(){
	Robot::drivebase->ResetGyro();
	Robot::drivebase->ResetEncoderPosition();
}

void TestAutoDriveStraight::Execute(){
	float ticks = prefs->GetFloat("AutoTicks", 5000);
	while(Robot::drivebase->ReturnEncoderDistance(0,0,0) <= ticks){
		Robot::drivebase->DriveStraight(-0.5);
	}
	//Robot::drivebase->DriveStraight(0.5);
	//Wait(0.5);
	End();
}

bool TestAutoDriveStraight::IsFinished(){
	return true;
}

void TestAutoDriveStraight::End(){
	Robot::drivebase->DriveStraight(0);
	Robot::drivebase->ResetEncoderPosition();
}

void TestAutoDriveStraight::Interrupted(){
	End();
}
