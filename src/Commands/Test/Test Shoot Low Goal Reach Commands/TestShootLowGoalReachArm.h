#ifndef TestShootLowGoalReachArm_H
#define TestShootLowGoalReachArm_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestShootLowGoalReachArm: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	TestShootLowGoalReachArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
