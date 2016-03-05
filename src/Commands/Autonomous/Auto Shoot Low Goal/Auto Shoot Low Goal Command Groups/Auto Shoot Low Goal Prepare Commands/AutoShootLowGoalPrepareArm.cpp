//Command that moves the arm into position to drive under the low bar
#include "AutoShootLowGoalPrepareArm.h"
#include "Robot.h"
#include "../../../../../RobotMap.h"

AutoShootLowGoalPrepareArm::AutoShootLowGoalPrepareArm(){
	Requires(Robot::ballmanipulator);
	prefs = Preferences::GetInstance();
}

void AutoShootLowGoalPrepareArm::Initialize(){

}

void AutoShootLowGoalPrepareArm::Execute(){
	float speed = prefs->GetFloat("AutoShootLowGoalArmSpeed", -1);
	float rollers = prefs->GetFloat("AutoShootLowGoalRollerSpeed", -0.75);
	Robot::ballmanipulator->RotateArm(speed);
	Robot::ballmanipulator->SetRollers(-rollers);
}

bool AutoShootLowGoalPrepareArm::IsFinished(){
	float angle = prefs->GetFloat("AutoShootLowGoalArmForward", 210);
	return ((angle - 5) < Robot::ballmanipulator->ReturnArmAngle()) && (Robot::ballmanipulator->ReturnArmAngle() < (angle + 5));
}

void AutoShootLowGoalPrepareArm::End(){
	Robot::ballmanipulator->RotateArm(0);
	Robot::ballmanipulator->SetRollers(0);
}

void AutoShootLowGoalPrepareArm::Interrupted(){
	End(); //Ends the command
}
