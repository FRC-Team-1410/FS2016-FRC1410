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
