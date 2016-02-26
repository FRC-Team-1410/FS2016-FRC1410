#include "AutoShootLowGoalDrive.h"
#include "Auto Shoot Low Goal Drive Commands/AutoShootLowGoalDriveStraight.h"

AutoShootLowGoalDrive::AutoShootLowGoalDrive(){
	AddParallel(new AutoShootLowGoalDriveStraight());
}
