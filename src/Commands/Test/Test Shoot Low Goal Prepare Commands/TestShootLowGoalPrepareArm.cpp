//Command that moves the arm into position to drive under the low bar
#include "TestShootLowGoalPrepareArm.h"
#include "Robot.h"
#include "../../../RobotMap.h"

TestShootLowGoalPrepareArm::TestShootLowGoalPrepareArm(){
	Requires(Robot::ballmanipulator);
	prefs = Preferences::GetInstance();
}

void TestShootLowGoalPrepareArm::Initialize(){

}

void TestShootLowGoalPrepareArm::Execute(){
	float speed = prefs->GetFloat("AutoShootLowGoalArmSpeed", -1);
	Robot::ballmanipulator->RotateArm(speed);
}

bool TestShootLowGoalPrepareArm::IsFinished(){
	float angle = prefs->GetFloat("AutoShootLowGoalArmForward", 210);
	return ((angle - 5) < Robot::ballmanipulator->ReturnArmAngle()) && (Robot::ballmanipulator->ReturnArmAngle() < (angle + 5));
}

void TestShootLowGoalPrepareArm::End(){
	Robot::ballmanipulator->RotateArm(0);
}

void TestShootLowGoalPrepareArm::Interrupted(){
	End(); //Ends the command
}
