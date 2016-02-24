#ifndef TeleOpActuateServo_H
#define TeleOpActuateServo_H

#include "Commands/Command.h"
#include "WPILib.h"

class TeleOpActuateServo: public Command {
private:
	Preferences * prefs; //Preferences object for retrieving values from the SmartDashboard
	float servo_position; //Position retrieved from the constructor object

public:
	TeleOpActuateServo(float position);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif
