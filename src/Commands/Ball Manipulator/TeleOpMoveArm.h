#ifndef TeleOpMoveArm_H
#define TeleOpMoveArm_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpMoveArm: public Command {
private:

public:
	TeleOpMoveArm();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
