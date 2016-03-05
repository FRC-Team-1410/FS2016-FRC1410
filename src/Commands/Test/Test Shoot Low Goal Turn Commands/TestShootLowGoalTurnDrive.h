#ifndef TestShootLowGoalTurnDrive_H
#define TestShootLowGoalTurnDrive_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestShootLowGoalTurnDrive: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	TestShootLowGoalTurnDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
