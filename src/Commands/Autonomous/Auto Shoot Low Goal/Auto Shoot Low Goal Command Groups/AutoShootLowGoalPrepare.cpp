#include "AutoShootLowGoalPrepare.h"
#include "Auto Shoot Low Goal Prepare Commands/AutoShootLowGoalPrepareArm.h"

AutoShootLowGoalPrepare::AutoShootLowGoalPrepare(){
	AddParallel(new AutoShootLowGoalPrepareArm());
}
