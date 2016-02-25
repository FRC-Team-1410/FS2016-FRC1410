#ifndef AutoCrossDefenseDriveStraight_H
#define AutoCrossDefenseDriveStraight_H

#include "Commands/Command.h"
#include "WPILib.h"

class AutoCrossDefenseDriveStraight: public Command {
private:
	Preferences * prefs; //Preferences object to grab values from the SmartDashboard
public:
	AutoCrossDefenseDriveStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
