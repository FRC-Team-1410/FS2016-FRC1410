#ifndef AutoShootLowGoalReachArm_H
#define AutoShootLowGoalReachArm_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalReachArm: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalReachArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
