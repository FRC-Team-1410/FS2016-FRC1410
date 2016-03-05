#include "TestShootLowGoalReach.h"
#include "Test Shoot Low Goal Reach Commands/TestShootLowGoalReachDrive.h"
#include "Test Shoot Low Goal Reach Commands/TestShootLowGoalReachArm.h"

TestShootLowGoalReach::TestShootLowGoalReach(){
	AddParallel(new TestShootLowGoalReachDrive());
	AddParallel(new TestShootLowGoalReachArm());
}
