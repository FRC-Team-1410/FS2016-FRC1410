#ifndef TeleOpRollersInwards_H
#define TeleOpRollersInwards_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpRollersInwards: public Command {
private:
	Preferences * prefs;
	float speed;
public:
	TeleOpRollersInwards();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
