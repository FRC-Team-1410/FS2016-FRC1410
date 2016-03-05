#ifndef TestShootLowGoalScoreRollers_H
#define TestShootLowGoalScoreRollers_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestShootLowGoalScoreRollers: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	TestShootLowGoalScoreRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
