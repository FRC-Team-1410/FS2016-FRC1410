#ifndef AutoShootLowGoalScoreStop_H
#define AutoShootLowGoalScoreStop_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalScoreStop: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalScoreStop();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
