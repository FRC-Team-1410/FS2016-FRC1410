#include "Robot.h"
#include "../RobotMap.h"
#include "DefenseManipulator.h"

DefenseManipulator::DefenseManipulator() : Subsystem("DefenseManipulator"){
	rotation_motor = new CANTalon(defenseRotationMotor);
	rotation_potentiometer = new AnalogPotentiometer(defensePotentiometerChannel, 360, 0);

	prefs = Preferences::GetInstance();
}

void DefenseManipulator::InitDefaultCommand(){

}

void DefenseManipulator::RotateManipulator(float speed){
	rotation_motor->Set(speed);
}

float DefenseManipulator::ReturnManipulatorAngle(){
	return rotation_potentiometer->Get();
}

bool DefenseManipulator::ReturnUpLimit(){
	return rotation_motor->IsFwdLimitSwitchClosed();
}

bool DefenseManipulator::ReturnDownLimit(){
	return rotation_motor->IsRevLimitSwitchClosed();
}
