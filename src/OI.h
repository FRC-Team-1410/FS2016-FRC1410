#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI{
private:
	Joystick * driver_stick;
	Joystick * operator_stick;
	Joystick * climber_stick;
	Preferences * prefs;

	JoystickButton * toggle_intake_inwards;
	JoystickButton * toggle_intake_outwards;
	JoystickButton * winch_climber;
	JoystickButton * rotate_climber;
	JoystickButton * winch_climb;
	JoystickButton * unwinch_climb;

public:
	OI();
	double GetDriveAxis(int axis);
	double GetOperatorAxis(int axis);
	double GetClimberAxis(int axis);
};

#endif
