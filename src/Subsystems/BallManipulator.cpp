#include "Robot.h"
#include "../RobotMap.h"
#include "BallManipulator.h"

BallManipulator::BallManipulator() : Subsystem("BallManipulator"){
	intake_motor = new CANTalon(ballIntakeMotor);
	rotation_motor = new CANTalon(ballRotationMotor);
	intake_potentiometer = new AnalogPotentiometer(ballPotentiometerChannel, 360, 0);

	prefs = Preferences::GetInstance();
}

void BallManipulator::InitDefaultCommand(){

}

void BallManipulator::DriveIntake(float speed){
	intake_motor->Set(speed);
}

float BallManipulator::ReturnIntakeSpeed(){
	intake_motor->SetFeedbackDevice(CANTalon::QuadEncoder);
	return intake_motor->GetEncVel();
}

void BallManipulator::RotateManipulator(float speed){
	rotation_motor->Set(speed);
}

float BallManipulator::ReturnManipulatorAngle(){
	return intake_potentiometer->Get();
}

bool BallManipulator::ReturnUpLimit(){
	return rotation_motor->IsFwdLimitSwitchClosed();
}

bool BallManipulator::ReturnDownLimit(){
	return rotation_motor->IsRevLimitSwitchClosed();
}
