#ifndef DefenseManipulator_H
#define DefenseManipulator_H

#include "WPILib.h"

class DefenseManipulator: public Subsystem{
private:
	CANTalon * rotation_motor;
	Potentiometer * rotation_potentiometer;

	Preferences * prefs;

public:
	DefenseManipulator();
	void InitDefaultCommand();
	void RotateManipulator(float speed);
	float ReturnManipulatorAngle();
	bool ReturnUpLimit();
	bool ReturnDownLimit();
};

#endif
