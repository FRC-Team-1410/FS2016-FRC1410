#ifndef TeleOpMoveManipulator_H
#define TeleOpMoveManipulator_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpMoveManipulator: public Command {
private:

public:
	TeleOpMoveManipulator();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
