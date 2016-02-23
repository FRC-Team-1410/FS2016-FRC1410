#ifndef BallManipulator_H
#define BallManipulator_H

#include "WPILib.h"

class BallManipulator: public Subsystem{
private:
	CANTalon * front_intake_motor;
	CANTalon * rotation_motor;
	Potentiometer * intake_potentiometer;
	Preferences * prefs;

public:
	BallManipulator();
	void InitDefaultCommand();
	void DriveIntake(float speed);
	float ReturnIntakeSpeed();
	void RotateManipulator(float speed);
	float ReturnManipulatorAngle();
	bool ReturnUpLimit();
	bool ReturnDownLimit();
};

#endif
