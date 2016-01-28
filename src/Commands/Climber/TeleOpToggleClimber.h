#ifndef TeleOpToggleClimber_H
#define TeleOpToggleClimber_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpToggleClimber: public Command {
private:
	Preferences * prefs;
	float speed;
	bool move_up;

public:
	TeleOpToggleClimber();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
