#ifndef TeleOpMoveDefense_H
#define TeleOpMoveDefense_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpMoveDefense: public Command {
private:
	bool up_limit;
	bool down_limit;

public:
	TeleOpMoveDefense();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
