#ifndef Climber_H
#define Climber_H

#include "WPILib.h"

class Climber: public Subsystem{
private:
	CANTalon * left_rotation;
	CANTalon * right_rotation;
	CANTalon * left_winch;
	Servo * ratchet_actuator;

	Preferences * prefs;

public:
	Climber();
	void InitDefaultCommand();
	void RotateClimber(float speed);
	void WinchClimber(float speed);
	bool ReturnUpLimit();
	bool ReturnDownLimit();
	void ActuateRatchet();
};

#endif
