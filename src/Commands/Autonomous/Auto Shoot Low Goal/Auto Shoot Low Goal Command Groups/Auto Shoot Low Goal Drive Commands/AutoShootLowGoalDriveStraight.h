#ifndef AutoShootLowGoalDriveStraight_H
#define AutoShootLowGoalDriveStraight_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoShootLowGoalDriveStraight: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoShootLowGoalDriveStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
