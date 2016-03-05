#ifndef AutoShootLowGoalScoreRollers_H
#define AutoShootLowGoalScoreRollers_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalScoreRollers: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalScoreRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
