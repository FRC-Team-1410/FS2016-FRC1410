#ifndef AutoShootLowGoalReachDrive_H
#define AutoShootLowGoalReachDrive_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalReachDrive: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalReachDrive();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
