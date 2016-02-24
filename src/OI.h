#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI{
private:
	Joystick * driver_stick; //Joystick for the driver
	Joystick * operator_stick; //Joystick for the operator
	Joystick * climber_stick; //Joystick for the climber
	Preferences * prefs; //Preferences to retrieve values from the SmartDashboard

	JoystickButton * rollers_in; //Button for running the rollers inwards
	JoystickButton * rollers_out; //Button for running the rollers outwards
	JoystickButton * winch_climber; //Button to winch the climbers
	JoystickButton * unwinch_climber; //Button to unwinch the climber
	JoystickButton * rotate_climber; //Button to rotate the climber
	JoystickButton * lock_gear; //Button to lock the gear in the climber
	JoystickButton * unlock_gear; //Button to unlock the gear in the climber

public:
	OI();

	double GetDriveAxis(int axis); //Method to return axes from the driver's stick
	double GetOperatorAxis(int axis); //Method to return axes from the operator's stick
	double GetClimberAxis(int axis); //Method to return axes from the climber's stick
};

#endif
