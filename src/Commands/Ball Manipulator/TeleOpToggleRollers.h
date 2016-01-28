#ifndef TeleOpToggleRollers_H
#define TeleOpToggleRollers_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpToggleRollers: public Command {
private:
	Preferences * prefs;
	float speed;
public:
	TeleOpToggleRollers();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
