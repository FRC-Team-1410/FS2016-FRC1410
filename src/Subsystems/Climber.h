#ifndef Climber_H
#define Climber_H

#include "WPILib.h"

class Climber: public Subsystem{
private:
	CANTalon * left_rotation; //Motor controller for the left rotation motor
	CANTalon * right_rotation; //Motor controller for the right rotation motor
	CANTalon * winch_motor; //Motor controller for the winch motor

	Servo * winch_servo; //Servo to stop the robot from falling

	Preferences * prefs; //Preferences to retrieve values from the SmartDashboard

public:
	Climber();
	void InitDefaultCommand();

	void RotateClimber(float speed); //Method to rotate climber
	void WinchClimber(float speed); //Method to winch climber
	bool ReturnUpLimit(); //Method to return if the climber is at the upper limit
	bool ReturnDownLimit(); //Method to return if the climber is at the lower limit
	bool ReturnWinchLimit(); //Method to return if the climber is completely winched in
	void MoveServo(float position); //Method to move the servo
};

#endif
