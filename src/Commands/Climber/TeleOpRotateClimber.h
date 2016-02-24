#ifndef TeleOpRotateClimber_H
#define TeleOpRotateClimber_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpRotateClimber: public Command {
private:
	Preferences * prefs; //Preferences object for retrieving values from the SmartDashboard

public:
	TeleOpRotateClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
