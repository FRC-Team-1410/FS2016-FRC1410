#ifndef TestShootLowGoalReachDrive_H
#define TestShootLowGoalReachDrive_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestShootLowGoalReachDrive: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	TestShootLowGoalReachDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
