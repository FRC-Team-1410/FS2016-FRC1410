#ifndef AutoShootLowGoalPrepareRollers_H
#define AutoShootLowGoalPrepareRollers_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalPrepareRollers: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalPrepareRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
