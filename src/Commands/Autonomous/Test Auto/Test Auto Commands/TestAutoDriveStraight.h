#ifndef TestAutoDriveStraight_H
#define TestAutoDriveStraight_H

#include "Commands/Command.h"
#include "WPILib.h"

class TestAutoDriveStraight: public Command {
private:
	float angle;
	float deviation;
	float left_speed;
	float right_speed;
public:
	TestAutoDriveStraight();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
