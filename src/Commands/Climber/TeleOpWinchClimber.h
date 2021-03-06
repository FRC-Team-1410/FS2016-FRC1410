#ifndef TeleOpWinchClimber_H
#define TeleOpWinchClimber_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpWinchClimber: public Command {
private:
	Preferences * prefs; //Preferences object for retrieving values from the SmartDashboard
	float climber_speed; //Speed retrieved from the constructor object

public:
	TeleOpWinchClimber(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
