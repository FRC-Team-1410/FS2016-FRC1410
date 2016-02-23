#ifndef TeleOpWinchClimber_H
#define TeleOpWinchClimber_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpWinchClimber: public Command {
private:
	Preferences * prefs;
	float climber_speed;

public:
	TeleOpWinchClimber(float speed);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
