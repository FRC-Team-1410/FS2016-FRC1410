//This is the default command for the subsystem BallManipulator
//It rotates the arm around the point
//That's about it
//It also returns the angle of the potentiometer for testing purposes
#include <Commands/Ball Manipulator/TeleOpMoveArm.h> //Includes the header file for this clas
#include "Robot.h" //Includes the Robot.h so we can use the OI methods
#include "../../RobotMap.h" //Includes the RobotMap.h which stores all our constants

TeleOpMoveArm::TeleOpMoveArm(){
	Requires(Robot::ballmanipulator); //Requires the ballmanipulator subsystem
}

void TeleOpMoveArm::Initialize(){
	//Nothing happens when the command is initialized
}

void TeleOpMoveArm::Execute(){
	//This method runs periodically while the command is being called
	//It sets the speed of the arm rotation to the value of the y axis of the left stick on the operator stick in the OI
	//The axis is 1
	Robot::ballmanipulator->RotateArm(Robot::oi->GetOperatorAxis(ballManipulatorMovement));
	Robot::ballmanipulator->ReturnArmAngle(); //Returns the angle of the arm for testing purposes
}

bool TeleOpMoveArm::IsFinished(){
	//Runs after each cycle of the roboRIO to check if the command is done
	//We never end this command so it is never finished
	//Thus it always returns false
	return false; //Returns false
}

void TeleOpMoveArm::End(){
	//Runs when the command is ended
	//This is usually only when TeleOp is disabled
	//It stops the arm rotation
	Robot::ballmanipulator->RotateArm(0); //Sets the rotation speed to 0
}

void TeleOpMoveArm::Interrupted(){
	//This runs when the command is interuppted
	//Basically this never runs
	//It just ends the command
	End(); //Ends the command
}
