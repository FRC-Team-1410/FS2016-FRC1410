#ifndef TeleOpRollersInwards_H
#define TeleOpRollersInwards_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpRollersInwards: public Command {
private:
	Preferences * prefs; //Preferences object to retrieve the speed of the rollers
	float speed; //Speed of the rollers
public:
	TeleOpRollersInwards();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
