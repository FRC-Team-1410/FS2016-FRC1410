#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI{
private:
	Joystick * driver_stick;
	Joystick * operator_stick;
	Joystick * climber_stick;
	Preferences * prefs;

	JoystickButton * rollers_in;
	JoystickButton * rollers_out;
	JoystickButton * winch_climber;
	JoystickButton * unwinch_climber;
	JoystickButton * rotate_climber;
	JoystickButton * lock_gear;
	JoystickButton * unlock_gear;

public:
	OI();
	double GetDriveAxis(int axis);
	double GetOperatorAxis(int axis);
	double GetClimberAxis(int axis);
};

#endif
