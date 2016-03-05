#ifndef AutoShootLowGoalPrepareArm_H
#define AutoShootLowGoalPrepareArm_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalPrepareArm: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalPrepareArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
