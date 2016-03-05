#ifndef TestShootLowGoalPrepareArm_H
#define TestShootLowGoalPrepareArm_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestShootLowGoalPrepareArm: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	TestShootLowGoalPrepareArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
