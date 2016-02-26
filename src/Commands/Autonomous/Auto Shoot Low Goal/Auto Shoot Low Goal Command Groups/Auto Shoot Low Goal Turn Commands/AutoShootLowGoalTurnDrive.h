#ifndef AutoShootLowGoalTurnDrive_H
#define AutoShootLowGoalTurnDrive_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalTurnDrive: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalTurnDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
