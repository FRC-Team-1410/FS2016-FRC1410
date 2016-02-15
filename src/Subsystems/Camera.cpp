#include "Robot.h"
#include "../RobotMap.h"
#include "Camera.h"
#include "Commands/Camera/TeleOpMoveCamera.h"
#include "SPI.h"

Camera::Camera() : Subsystem("DriveBase"){
	rotation_motor = new Servo(0);
	tilt_motor = new Servo(1);
	prefs = Preferences::GetInstance();
}

void Camera::InitDefaultCommand(){
	SetDefaultCommand(new TeleOpMoveCamera());
}

void Camera::MoveCamera(float rotation, float tilt){
	rotation_motor->Set((rotation + 1) / 2);
	tilt_motor->Set((tilt + 1) / 2);
}

void Camera::SetCamera(){
	rotation_motor->Set(1);
	tilt_motor->Set(1);
}
