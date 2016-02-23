#include "Robot.h"
#include "../RobotMap.h"
#include "BallManipulator.h"
#include "../Commands/Ball Manipulator/TeleOpMoveIntake.h"

BallManipulator::BallManipulator() : Subsystem("BallManipulator"){
	front_intake_motor = new CANTalon(frontIntakeMotor);
	rotation_motor = new CANTalon(ballRotationMotor);
	intake_potentiometer = new AnalogPotentiometer(ballPotentiometerChannel, 360, 0);

	prefs = Preferences::GetInstance();
}

void BallManipulator::InitDefaultCommand(){
	SetDefaultCommand(new TeleOpMoveIntake());
}

void BallManipulator::DriveIntake(float speed){
	float multiplier = prefs->GetFloat("RollerDirection", 1);
	front_intake_motor->Set(speed * multiplier);
}

float BallManipulator::ReturnIntakeSpeed(){
	front_intake_motor->SetFeedbackDevice(CANTalon::QuadEncoder);
	return front_intake_motor->GetEncVel();
}

void BallManipulator::RotateManipulator(float speed){
	bool forward = prefs->GetBoolean("BallForward", true);
	if(forward){
		rotation_motor->Set(speed * -0.5);
	}
	else{
		rotation_motor->Set(speed * 0.5);
	}

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
