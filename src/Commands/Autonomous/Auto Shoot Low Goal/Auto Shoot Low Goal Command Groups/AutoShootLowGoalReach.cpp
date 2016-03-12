#include "AutoShootLowGoalReach.h"
#include "Auto Shoot Low Goal Reach Commands/AutoShootLowGoalReachDrive.h"
#include "Auto Shoot Low Goal Reach Commands/AutoShootLowGoalReachArm.h"

AutoShootLowGoalReach::AutoShootLowGoalReach(){
	//AddSequential(new AutoShootLowGoalReachArm());
	AddParallel(new AutoShootLowGoalReachDrive());
}
