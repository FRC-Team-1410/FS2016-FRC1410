#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI{
private:
	Joystick * driver_stick;
	Joystick * operator_stick;
	Preferences * prefs;

public:
	OI();
	double GetDriveAxis(int axis);
	double GetOperatorAxis(int axis);
};

#endif
