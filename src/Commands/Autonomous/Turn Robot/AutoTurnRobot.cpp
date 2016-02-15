#include "AutoTurnRobot.h"
#include "Turn Robot Commands/TurnRobotNinetyTurn.h"

AutoTurnRobot::AutoTurnRobot(){
	AddSequential(new TurnRobotNinetyTurn());
}
