#ifndef TestShootLowGoalDriveStraight_H
#define TestShootLowGoalDriveStraight_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestShootLowGoalDriveStraight: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	TestShootLowGoalDriveStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
