#ifndef TeleOpMoveIntake_H
#define TeleOpMoveIntake_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpMoveIntake: public Command {
private:
	bool up_limit;
	bool down_limit;

public:
	TeleOpMoveIntake();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
