/*
* RobotMap defines motor and sensor ports and buttons/axis for the robot.
* This is for ease of use and so that we can easily make sure that there
* are no conflicts with ports, constants, etc.
*/

#ifndef ROBOTMAP_H_
#define ROBOTMAP_H_

//Motors

//DriveBase motors
const int frontLeftDrive = 1;
const int frontRightDrive = 2;
const int backLeftDrive = 3;
const int backRightDrive = 4;

//Climber motors
const int leftClimberRotation = 5;
const int rightClimberRotation = 6;
const int leftClimberWinch = 7;

//BallManipulator motors
const int ballIntakeMotor = 8;
const int ballRotationMotor = 9;

//DefenseManiuplator motors
const int defenseRotationMotor = 10;

//Actuators
const int climberRatchetActuator = 1;

//Analog inputs
const int autoDriveGyro = 0;
const int ballPotentiometerChannel = 1;
const int defensePotentiometerChannel = 2;

//Controller constants
const int tankLeftAxis = 1;
const int tankRightAxis = 5;

#endif /* ROBOTMAP_H_ */
