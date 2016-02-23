//This is the TeleOpDriveRobot command
//It is the default, and only command, for the DriveBase subsystem
//It drives the robot using inputs from the y-axis of both sticks on the operator_stick found in OI
//Those axes are 1 for the left and 5 for the right
#include <Commands/Drive Base/TeleOpDriveRobot.h> //Includes the header file for this class
#include "Robot.h" //Includes Robot.h so we can use the OI's methods
#include "../../RobotMap.h" //Includes RobotMap.h which is where all the constants used are stored

TeleOpDriveRobot::TeleOpDriveRobot(){
	Requires(Robot::drivebase); //Tells the roboRIO that this command requires the drivebase
}

void TeleOpDriveRobot::Initialize(){
	Robot::drivebase->ResetEncoderPosition(); //Resets the encoder position so we can see how much we drove during the match
}

void TeleOpDriveRobot::Execute(){
	//This is the method that runs constantly while the command is being called
	//Since the following line is long I will explain it above the line
	//DriveExponential is called, with left_speed being the value read from axis 1 on the driver stick times -1
	//And right_speed is the value read from axis 5 on the driver stick
	Robot::drivebase->DriveExponential(Robot::oi->GetDriveAxis(tankLeftAxis), -1 * Robot::oi->GetDriveAxis(tankRightAxis));
	Robot::drivebase->ReturnEncoderDistance(0, 0, 0); //Calls ReturnEncoderDistance to show us how much we have driven during a match
}

bool TeleOpDriveRobot::IsFinished(){
	//This method is read every cycle by the roboRIO to see if the command is ever done
	//We never stop driving so it always says false
	return false; //Returns false
}

void TeleOpDriveRobot::End(){
	//This method runs when the command is ended
	//This only happens when TeleOp is Disabled
	//Thus is stops the robot
	Robot::drivebase->DriveExponential(0, 0); //Sets both left_speed and right_speed to 0
}

void TeleOpDriveRobot::Interrupted(){
	//This method only runs if the command is interrupted
	//Basically, never.
	End(); //Just runs the End() method
}
