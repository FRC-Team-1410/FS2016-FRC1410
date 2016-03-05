#include "AutoShootLowGoalScore.h"
#include "Auto Shoot Low Goal Score Commands/AutoShootLowGoalScoreRollers.h"
#include "Auto Shoot Low Goal Score Commands/AutoShootLowGoalScoreStop.h"

AutoShootLowGoalScore::AutoShootLowGoalScore(){
	AddParallel(new AutoShootLowGoalScoreRollers());
	AddParallel(new AutoShootLowGoalScoreStop());
}
