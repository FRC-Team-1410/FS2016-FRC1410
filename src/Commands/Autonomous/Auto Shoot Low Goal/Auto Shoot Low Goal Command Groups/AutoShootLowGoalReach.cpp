#include "AutoShootLowGoalReach.h"
#include "Auto Shoot Low Goal Reach Commands/AutoShootLowGoalReachDrive.h"
#include "Auto Shoot Low Goal Reach Commands/AutoShootLowGoalReachArm.h"

AutoShootLowGoalReach::AutoShootLowGoalReach(){
	AddParallel(new AutoShootLowGoalReachDrive());
	AddParallel(new AutoShootLowGoalReachArm());
}
