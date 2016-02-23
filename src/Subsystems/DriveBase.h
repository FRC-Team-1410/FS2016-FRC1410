#ifndef DriveBase_H
#define DriveBase_H

#include "WPILib.h"

class DriveBase: public Subsystem{
private:
	CANTalon * fl_motor; //Motor controller for the front left motor
	CANTalon * fr_motor; //Motor controller for the front right motor
	CANTalon * bl_motor; //Motor controller for the back left motor
	CANTalon * br_motor; //Motor controller for the back right motor

	AnalogGyro * drive_gyro; //Gyro used in autonomous

	Preferences * prefs; //Preferences used to get values from SmartDashboard

public:
	DriveBase();
	void InitDefaultCommand();
	void DriveTank(float left_speed, float right_speed); //For driving in tank mode
	void DriveExponential(float left_speed, float right_speed); //Drives in tank, but with an exponential curve for the inputs

	float ReturnEncoderDistance(float e1, float e2, float distance); //Returns the distance driven in encoder ticks
	void ResetEncoderPosition(); //Resets the encoder position to zero

	float ReturnGyroPosition(); //Returns the current angle of the gyro
	void ResetGyro(); //Resets the gyro angle to zero
	void CalibrateGyro(); //Calibrates the gyro
};

#endif
