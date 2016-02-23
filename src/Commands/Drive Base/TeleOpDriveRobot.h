#ifndef TeleOpDriveRobot_H
#define TeleOpDriveRobot_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpDriveRobot: public Command {
private:

public:
	TeleOpDriveRobot();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
