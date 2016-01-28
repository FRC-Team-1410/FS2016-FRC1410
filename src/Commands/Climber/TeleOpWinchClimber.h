#ifndef TeleOpWinchClimber_H
#define TeleOpWinchClimber_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpWinchClimber: public Command {
private:
	Preferences * prefs;
	float speed;

public:
	TeleOpWinchClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
