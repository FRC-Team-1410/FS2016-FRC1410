#ifndef DriveBase_H
#define DriveBase_H

#include "WPILib.h"
#include "SPI.h"

class DriveBase: public Subsystem{
private:
	CANTalon * fl_motor;
	CANTalon * fr_motor;
	CANTalon * bl_motor;
	CANTalon * br_motor;

	AnalogGyro * drive_gyro;

	Preferences * prefs;

public:
	DriveBase();
	void InitDefaultCommand();
	void DriveTank(float left_speed, float right_speed);
	void DriveExponential(float left_speed, float right_speed);

	float ReturnEncoderDistance(float e1, float e2, float distance);
	void ResetEncoderPosition();

	void PutGyroAngle(float angle);
	float ReturnGyroPosition();
	void ResetGyro();
	void CalibrateGyro();

	void DriveStraight(float speed);
};

#endif
