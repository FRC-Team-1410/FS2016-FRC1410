//This is the command that actuates the servo to stop the climber
//We recent decided that we wanted it to unactuate it too
//So now it has a float position parameter in the constructor
//Why?
//So this command does both things!
//Wooooooooooooooooooooooooo parameters
//Anyways it does this by setting the position of the servo
#include <Commands/Climber/TeleOpActuateServo.h> //Includes the header file for this class
#include "Robot.h" //Includes Robot.h so that the OI methods can be used
#include "../../RobotMap.h" //Includes RobotMap.h for all the constants stored there

TeleOpActuateServo::TeleOpActuateServo(float position){
	Requires(Robot::climber); //Requires the climber class

	prefs = Preferences::GetInstance(); //Initializes the prefs object in this class
	servo_position = position; //Retrieves the position value from the constructor and puts it into servo_position
}

void TeleOpActuateServo::Initialize(){
	//Nothing happens when this command is initialized
}

void TeleOpActuateServo::Execute(){
	//This method runs while the command is being called
	Robot::climber->MoveServo(servo_position); //Moves the servo to servo_position
	End(); //Ends the command because the servo has been set to a position
}

bool TeleOpActuateServo::IsFinished(){
	//This never really gets checked but it returns true just incase
	return true;
}

void TeleOpActuateServo::End(){
	//Nothing happens at the end of the command
}

void TeleOpActuateServo::Interrupted(){
	//This method runs when the command is interrupted
	//It literally just ends the command
	End(); //Ends the command
}
