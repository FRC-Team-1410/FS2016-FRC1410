//Command that moves the arm into position to drive under the low bar
#include "AutoShootLowGoalPrereachArm.h"
#include "Robot.h"
#include "../../../../../RobotMap.h"

AutoShootLowGoalPrereachArm::AutoShootLowGoalPrereachArm(){
	Requires(Robot::ballmanipulator);
	prefs = Preferences::GetInstance();
}

void AutoShootLowGoalPrereachArm::Initialize(){

}

void AutoShootLowGoalPrereachArm::Execute(){
	float speed = prefs->GetFloat("AutoShootLowGoalArmSpeed", -1);
	float rollers = prefs->GetFloat("AutoShootLowGoalRollerSpeed", -0.75);
	Robot::ballmanipulator->RotateArm(-speed);
	Robot::ballmanipulator->SetRollers(-rollers);
}

bool AutoShootLowGoalPrereachArm::IsFinished(){
	float angle = prefs->GetFloat("AutoShootLowGoalArmBackward", 145);
	return ((angle - 5) < Robot::ballmanipulator->ReturnArmAngle()) && (Robot::ballmanipulator->ReturnArmAngle() < (angle + 5));
}

void AutoShootLowGoalPrereachArm::End(){
	Robot::ballmanipulator->RotateArm(0);
	Robot::ballmanipulator->SetRollers(0);
}

void AutoShootLowGoalPrereachArm::Interrupted(){
	End(); //Ends the command
}
