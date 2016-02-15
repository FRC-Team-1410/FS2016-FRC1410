#ifndef TurnRobotNinetyTurn_H
#define TurnRobotNinetyTurn_H

#include "Commands/Command.h"
#include "WPILib.h"

class TurnRobotNinetyTurn: public Command {
private:
	Preferences * prefs;
public:
	TurnRobotNinetyTurn();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
