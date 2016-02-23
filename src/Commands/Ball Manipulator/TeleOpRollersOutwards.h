#ifndef TeleOpRollersOutwards_H
#define TeleOpRollersOutwards_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpRollersOutwards: public Command {
private:
	Preferences * prefs; //Preferences object to retrieve the the speed of the rollers
	float speed; //Speed of the rollers
public:
	TeleOpRollersOutwards();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
