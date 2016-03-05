#include "TestShootLowGoalTurn.h"
#include "Test Shoot Low Goal Turn Commands/TestShootLowGoalTurnDrive.h"

TestShootLowGoalTurn::TestShootLowGoalTurn(){
	AddParallel(new TestShootLowGoalTurnDrive());
}
