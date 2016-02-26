#include "AutoShootLowGoalTurn.h"
#include "Auto Shoot Low Goal Turn Commands/AutoShootLowGoalTurnDrive.h"

AutoShootLowGoalTurn::AutoShootLowGoalTurn(){
	AddParallel(new AutoShootLowGoalTurnDrive());
}
