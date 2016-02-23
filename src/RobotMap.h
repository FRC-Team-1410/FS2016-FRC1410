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
const int rightClimberRotation = 7;
const int leftClimberWinch = 8;

//BallManipulator motors
const int frontIntakeMotor = 9;
const int backIntakeMotor = 11;
const int ballRotationMotor = 6;

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

const int ballManipulatorMovement = 5;
const int cameraTiltAxis = 1;
const int cameraRotationAxis = 0;

const int climberRotationAxis = 1;
const int climberWinchButton = 1;
const int climberUnwinchButton = 2;
const int climberJustRotate = 3;


//Buttons
const int toggleIntakeInwards = 1;
const int toggleIntakeOutwards = 2;
const int winchClimber = 3;
const int toggleClimberSolenoid = 4;

#endif /* ROBOTMAP_H_ */
