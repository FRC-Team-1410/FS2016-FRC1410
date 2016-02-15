#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI{
private:
	Joystick * driver_stick;
	Joystick * operator_stick;
	Joystick * camera_stick;
	Preferences * prefs;

	JoystickButton * toggle_intake_inwards;
	JoystickButton * toggle_intake_outwards;
	JoystickButton * winch_climber;
	JoystickButton * toggle_climber_solenoid;
	JoystickButton * set_camera;

public:
	OI();
	double GetDriveAxis(int axis);
	double GetOperatorAxis(int axis);
	double GetCameraAxis(int axis);
};

#endif
