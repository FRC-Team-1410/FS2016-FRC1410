#include "Robot.h"
#include "../RobotMap.h"
#include "DriveBase.h"
#include "Commands/Drive Base/TeleOpTankDrive.h"

DriveBase::DriveBase() : Subsystem("DriveBase"){
	fl_motor = new CANTalon(frontLeftDrive);
	fr_motor = new CANTalon(frontRightDrive);
	bl_motor = new CANTalon(backLeftDrive);
	br_motor = new CANTalon(backRightDrive);

	drive_gyro = new AnalogGyro(autoDriveGyro);

	prefs = Preferences::GetInstance();
}

void DriveBase::InitDefaultCommand(){
	SetDefaultCommand(new TeleOpTankDrive());
}

void DriveBase::DriveTank(float left_speed, float right_speed){
	fl_motor->Set(left_speed);
	fr_motor->Set(right_speed);
	bl_motor->Set(left_speed);
	br_motor->Set(right_speed);
}

void DriveBase::DriveExponential(float l, float r){
	float left_exponential;
	float right_exponential;
	int exponential_mode = prefs->GetInt("ExponentialMode", 1);

	if(exponential_mode == 1){
		left_exponential = l;
		right_exponential = r;
	}
	else if(exponential_mode == 2){
		left_exponential = l * l * l;
		right_exponential = r * r * r;
	}
	else if(exponential_mode == 3){
		left_exponential = (l + (l * l * l)) / 2;
		right_exponential = (r + (r * r * r)) / 2;
	}
	else if(exponential_mode == 4){
		left_exponential = (l + (l * l * l) + (l * l * l * l * l)) / 3;
		right_exponential = (r + (r * r * r) + (r * r * r * r * r)) / 3;
	}
	else{
		left_exponential = l;
		right_exponential = r;
	}
	fl_motor->Set(left_exponential);
	fr_motor->Set(right_exponential);
	bl_motor->Set(left_exponential);
	br_motor->Set(right_exponential);
}

float DriveBase::ReturnEncoderDistance(float e1, float e2, float distance){
	fl_motor->SetFeedbackDevice(CANTalon::QuadEncoder);
	fr_motor->SetFeedbackDevice(CANTalon::QuadEncoder);
	//fl_motor->SetSensorDirection(true);
	//fr_motor->SetSensorDirection(true);

	e1 = fl_motor->GetEncPosition();
	e2 = fr_motor->GetEncPosition() * -1;

	distance = (e2 + e1) / 2;
	SmartDashboard::PutNumber("Encoder Distance", distance);
	return distance;
}

void DriveBase::ResetEncoderPosition(){
	SmartDashboard::PutNumber("Encoder Distance", 0);
	bl_motor->SetPosition(0);
	br_motor->SetPosition(0);
}

float DriveBase::ReturnGyroPosition(){
	float angle = drive_gyro->GetAngle();
	if(angle > 180){
		angle -= 360;
	}
	return angle;
}

void DriveBase::ResetGyro(){
	drive_gyro->Reset();
}


