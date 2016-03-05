#include "TestShootLowGoalScore.h"
#include "Test Shoot Low Goal Score Commands/TestShootLowGoalScoreRollers.h"
#include "Test Shoot Low Goal Score Commands/TestShootLowGoalScoreStop.h"

TestShootLowGoalScore::TestShootLowGoalScore(){
	AddParallel(new TestShootLowGoalScoreRollers());
	AddParallel(new TestShootLowGoalScoreStop());
}
