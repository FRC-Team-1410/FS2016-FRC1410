//This is the class for our BallManipulator Subsystem
//Our BallManipulator is used to pick up boulders, lift the portcullis, and use the Chival de Frise
//It has a motor to rotate the arm and a motor to run some wheels used to intake the boulder
//Those motors are:
//rotation_motor and intake_motor
//They are the motor that rotates the arm and the motor that runs the wheels, respectively
//There is also an AnalogPotentiometer
//This is used during Auto to move the arm to the correct point to score in the low goal
#include <Commands/Ball Manipulator/TeleOpMoveArm.h> //Includes the default command
#include "Robot.h" //Includes the Robot.h don't know why, but too scared to remove it
#include "../RobotMap.h" //Includes the RobotMap.h which is where all our constants are stored
#include "BallManipulator.h" //includes the header file for this class

BallManipulator::BallManipulator() : Subsystem("BallManipulator"){
	rotation_motor = new CANTalon(ballRotationMotor); //CAN ID 6
	intake_motor = new CANTalon(intakeMotorID); //CAN ID 9

	arm_potentiometer = new AnalogPotentiometer(ballPotentiometerChannel, 360, 0); //Analog Port 1

	prefs = Preferences::GetInstance(); //Initializes the prefs object in this class
}

void BallManipulator::InitDefaultCommand(){
	//This method sets the default command for the subsystem
	//This makes it so that we do not have to call the command ourselves
	//It just runs automatically when TeleOp is enabled
	SetDefaultCommand(new TeleOpMoveArm()); //Sets the default command to TeleOpMoveArm, which moves the arm
}

void BallManipulator::SetRollers(float speed){
	//This method sets the speed of the intake rollers
	//There is a multiplier who's value is set from SmartDashboard
	//The multiplier allows us to make the rollers run faster or slower
	//For example, if multiplier is 0.67, the rollers run at 2/3 of the input speed
	float multiplier = prefs->GetFloat("BallManipulatorRollerMultiplier", -1); //Retrieves the value of the multiplier (default value is 1)
	SmartDashboard::PutNumber("Roller Speed", speed * multiplier); //Puts the speed * multiplier on the SmartDashboard
	intake_motor->Set(speed * multiplier); //Sets the speed of the rollers to the input speed times the multiplier
}

void BallManipulator::RotateArm(float speed){
	//This method rotates the arm by setting the speed of rotation_motor to an input
	//There is also a multiplier who's value is set from SmartDashboard
	//This multiplier slows down or speeds up the rate at which the arm rotates
	//For example, if multiplier is 0.75, the arm rotates at 3/4 speed
	float multiplier = prefs->GetFloat("BallManipulatorArmMultiplier", 0.5); //Retrieves the value of multiplier (default is 0.5)
	SmartDashboard::PutNumber("Arm Speed", speed * multiplier);
	rotation_motor->Set(speed * multiplier); //Sets the speed of the rotation to the input speed times multiplier
}

float BallManipulator::ReturnArmAngle(){
	//This method returns the angle of the arm
	//This method is used in Auto
	//It is unknown if it returns in degrees or not
	//When the potentiometer is tested, this will be updated
	SmartDashboard::PutNumber("Arm Angle", arm_potentiometer->Get()); //Puts the arm angle onto SmartDashboard
	return arm_potentiometer->Get(); //Returns the value from the potentiometer attached to the arm
}
