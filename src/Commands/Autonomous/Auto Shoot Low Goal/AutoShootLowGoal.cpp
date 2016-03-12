#include "AutoShootLowGoal.h"
#include "Auto Shoot Low Goal Command Groups/AutoShootLowGoalTurn.h"
#include "Auto Shoot Low Goal Command Groups/AutoShootLowGoalScore.h"
#include "Auto Shoot Low Goal Command Groups/AutoShootLowGoalReach.h"
#include "Auto Shoot Low Goal Command Groups/AutoShootLowGoalDrive.h"
#include "Auto Shoot Low Goal Command Groups/AutoShootLowGoalPrepare.h"
#include "Auto Shoot Low Goal Command Groups/AutoShootLowGoalPrereach.h"

AutoShootLowGoal::AutoShootLowGoal(){
	AddSequential(new AutoShootLowGoalPrepare());
	AddSequential(new AutoShootLowGoalDrive());
	AddSequential(new AutoShootLowGoalTurn());
	AddSequential(new AutoShootLowGoalPrereach());
	AddSequential(new AutoShootLowGoalReach());
	AddSequential(new AutoShootLowGoalScore());
}
