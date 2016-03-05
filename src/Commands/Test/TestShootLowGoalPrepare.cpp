#include "TestShootLowGoalPrepare.h"
#include "Test Shoot Low Goal Prepare Commands/TestShootLowGoalPrepareArm.h"

TestShootLowGoalPrepare::TestShootLowGoalPrepare(){
	AddParallel(new TestShootLowGoalPrepareArm());
}
