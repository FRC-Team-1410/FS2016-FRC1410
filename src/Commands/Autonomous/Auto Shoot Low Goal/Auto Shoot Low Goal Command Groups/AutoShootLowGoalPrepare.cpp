#include "AutoShootLowGoalPrepare.h"
#include "Auto Shoot Low Goal Prepare Commands/AutoShootLowGoalPrepareArm.h"
#include "Auto Shoot Low Goal Prepare Commands/AutoShootLowGoalPrepareRollers.h"

AutoShootLowGoalPrepare::AutoShootLowGoalPrepare(){
	AddParallel(new AutoShootLowGoalPrepareArm());
	//AddParallel(new AutoShootLowGoalPrepareRollers());
}
