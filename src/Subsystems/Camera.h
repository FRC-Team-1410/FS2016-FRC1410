#ifndef Camera_H
#define Camera_H

#include "WPILib.h"
#include "SPI.h"

class Camera: public Subsystem{
private:
	Servo * rotation_motor;
	Servo * tilt_motor;

	Preferences * prefs;

public:
	Camera();
	void InitDefaultCommand();

	void MoveCamera(float rotation, float tilt);
	void SetCamera();
};

#endif
