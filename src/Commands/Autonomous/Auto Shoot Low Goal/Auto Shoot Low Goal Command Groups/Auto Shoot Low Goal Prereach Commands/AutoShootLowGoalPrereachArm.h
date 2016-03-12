#ifndef AutoShootLowGoalPrereachArm_H
#define AutoShootLowGoalPrereachArm_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalPrereachArm: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalPrereachArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
