#ifndef TestShootLowGoalScoreStop_H
#define TestShootLowGoalScoreStop_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestShootLowGoalScoreStop: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	TestShootLowGoalScoreStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
