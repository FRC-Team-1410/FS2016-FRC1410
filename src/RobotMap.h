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

//Climber servos
const int climberServoPWM = 0;

//BallManipulator motors
const int intakeMotorID = 9;
const int ballRotationMotor = 6;

//Camera servos
const int cameraRotationServo = 2;
const int cameraTiltServo = 3;

//Analog inputs
const int autoDriveGyro = 0;
const int ballPotentiometerChannel = 1;

//Controller constants
const int tankLeftAxis = 1;
const int tankRightAxis = 5;

const int ballManipulatorMovement = 5;

const int climberRotationAxis = 1;

//Controllers
const int driverStickPort = 0;
const int operatorStickPort = 1;
const int climberStickPort = 2;

//Buttons
const int rollersInButton = 1;
const int rollersOutButton = 2;
const int winchClimberButton = 2;
const int unwinchClimberButton = 1;
const int rotateClimberButton = 3;
const int lockGearButton = 8;
const int unlockGearButton = 9;

#endif /* ROBOTMAP_H_ */
