#ifndef TestAutoDriveStraight_H
#define TestAutoDriveStraight_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestAutoDriveStraight: public Command {
private:
	Preferences * prefs;
	float ticks;
public:
	TestAutoDriveStraight(float distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
