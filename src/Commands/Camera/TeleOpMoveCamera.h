#ifndef TeleOpMoveCamera_H
#define TeleOpMoveCamera_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpMoveCamera: public Command {
private:

public:
	TeleOpMoveCamera();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
