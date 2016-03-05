//Command that moves the arm into position to shoot the ball into the low goal
#include "AutoShootLowGoalPrepareRollers.h"
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

AutoShootLowGoalPrepareRollers::AutoShootLowGoalPrepareRollers(){
	Requires(Robot::ballmanipulator); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void AutoShootLowGoalPrepareRollers::Initialize(){
	//This method runs only when the command is initialized
	//Nothing happens
}

void AutoShootLowGoalPrepareRollers::Execute(){
	//This method runs while the command is active
	float speed = prefs->GetFloat("AutoShootLowGoalRollerSpeed", -0.75); //Retrieves the angle to move the arm from the SmartDashboard
	Robot::ballmanipulator->SetRollers(-speed);
	Wait(0.5);
	End(); //Ends the command when the robot has driven the expected amount of ticks
}

bool AutoShootLowGoalPrepareRollers::IsFinished(){
	//This runs when the scheduler checks if the command is done
	//The command is always done
	//ALWAYS
	//A
	//L
	//W
	//A
	//Y
	//S
	return true; //Returns true
}

void AutoShootLowGoalPrepareRollers::End(){
	//This method is run when the command is ended
	//Nothing happens
	//Except it does stop the arm from rotating anymore once in position
	Robot::ballmanipulator->SetRollers(0); //Stops the arm at the correct position
}

void AutoShootLowGoalPrepareRollers::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
