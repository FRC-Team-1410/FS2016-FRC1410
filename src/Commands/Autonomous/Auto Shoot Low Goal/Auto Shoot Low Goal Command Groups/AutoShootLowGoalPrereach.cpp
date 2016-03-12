#include "AutoShootLowGoalPrereach.h"
#include "Auto Shoot Low Goal Prereach Commands/AutoShootLowGoalPrereachArm.h"

AutoShootLowGoalPrereach::AutoShootLowGoalPrereach(){
	AddParallel(new AutoShootLowGoalPrereachArm());
}
