#include "Robot.h"
#include "../RobotMap.h"
#include "Climber.h"

Climber::Climber() : Subsystem("Climber"){
	left_rotation = new CANTalon(leftClimberRotation);
	right_rotation = new CANTalon(rightClimberRotation);
	left_winch = new CANTalon(leftClimberWinch);
	ratchet_actuator = new Servo(climberRatchetActuator);

	prefs = Preferences::GetInstance();
}

void Climber::InitDefaultCommand(){

}

void Climber::RotateClimber(float speed){
	left_rotation->Set(speed);
	right_rotation->Set(speed);
}

void Climber::WinchClimber(float speed){
	left_winch->Set(speed);
}

bool Climber::ReturnUpLimit(){
	return left_winch->IsFwdLimitSwitchClosed();
}

bool Climber::ReturnDownLimit(){
	return left_winch->IsRevLimitSwitchClosed();
}

void Climber::ActuateRatchet(){
	ratchet_actuator->Set(0.5);
}
