#include "TestShootLowGoalDrive.h"
#include "Test Shoot Low Goal Drive Commands/TestShootLowGoalDriveStraight.h"

TestShootLowGoalDrive::TestShootLowGoalDrive(){
	AddParallel(new TestShootLowGoalDriveStraight());
}
