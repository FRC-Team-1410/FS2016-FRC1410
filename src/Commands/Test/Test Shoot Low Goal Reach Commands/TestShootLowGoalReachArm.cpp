//Command that moves the arm into position to shoot the ball into the low goal
#include "TestShootLowGoalReachArm.h"
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

TestShootLowGoalReachArm::TestShootLowGoalReachArm(){
	Requires(Robot::ballmanipulator); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void TestShootLowGoalReachArm::Initialize(){
	//This method runs only when the command is initialized
	//Nothing happens
}

void TestShootLowGoalReachArm::Execute(){
	//This method runs while the command is active
	float speed = prefs->GetFloat("AutoshootLowGoalArmSpeed", -1); //Retrieves the speed for the arm from the SmartDashboard
	Robot::ballmanipulator->RotateArm(-speed);
}

bool TestShootLowGoalReachArm::IsFinished(){
	//This runs when the scheduler checks if the command is done
	//The command is always done
	//ALWAYS
	//A
	//L
	//W
	//A
	//Y
	//S
	float angle = prefs->GetFloat("AutoShootLowGoalArmBackwards",  307); //Retrieves the angle to move the arm from the SmartDashboard
	return ((angle - 5) < Robot::ballmanipulator->ReturnArmAngle()) && (Robot::ballmanipulator->ReturnArmAngle() < (angle + 5));
}

void TestShootLowGoalReachArm::End(){
	//This method is run when the command is ended
	//Nothing happens
	//Except it does stop the arm from rotating anymore once in position
	Robot::ballmanipulator->RotateArm(0); //Stops the arm at the correct position
}

void TestShootLowGoalReachArm::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
