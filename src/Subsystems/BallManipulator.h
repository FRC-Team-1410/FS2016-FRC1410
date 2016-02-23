#ifndef BallManipulator_H
#define BallManipulator_H

#include "WPILib.h"

class BallManipulator: public Subsystem{
private:
	CANTalon * rotation_motor; //Motor controller for the motor that rotates the arm
	CANTalon * intake_motor; //Motor controller for the motor that runs the intake rollers

	Potentiometer * arm_potentiometer; //Potentiometer used in Autonomous

	Preferences * prefs; //Preferences used to get values from SmartDashboard

public:
	BallManipulator();
	void InitDefaultCommand();

	void SetRollers(float speed);

	void RotateArm(float speed);
	float ReturnArmAngle();
};

#endif
