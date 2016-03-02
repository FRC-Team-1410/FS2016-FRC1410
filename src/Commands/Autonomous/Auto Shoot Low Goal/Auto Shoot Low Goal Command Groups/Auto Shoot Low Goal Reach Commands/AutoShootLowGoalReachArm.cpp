//Command that moves the arm into position to shoot the ball into the low goal
#include "AutoShootLowGoalReachArm.h" //Includes the header file for this class
#include "Robot.h" //Includes Robot.h to use for methods from the subsystems
#include "../../../../../RobotMap.h" //Includes RobotMap.h for the constants stored in there

AutoShootLowGoalReachArm::AutoShootLowGoalReachArm(){
	Requires(Robot::ballmanipulator); //Requires the drivebase from Robot
	prefs = Preferences::GetInstance(); //Instantiates the prefs object in this class
}

void AutoShootLowGoalReachArm::Initialize(){
	//This method runs only when the command is initialized
	//Nothing happens
}

void AutoShootLowGoalReachArm::Execute(){
	//This method runs while the command is active
	float angle = prefs->GetFloat("AutoShootLowGoalArm", 135); //Retrieves the angle to move the arm from the SmartDashboard
	float speed = prefs->GetFloat("AutoshootLowGoalSpeed", 0.5); //Retrieves the speed for the arm from the SmartDashboard
	while(Robot::ballmanipulator->ReturnArmAngle() <= angle){
		//This loop runs until the arm is at the correct angle
		//Angle is in degrees
		Robot::ballmanipulator->RotateArm(speed);
	}
	End(); //Ends the command when the robot has driven the expected amount of ticks
}

bool AutoShootLowGoalReachArm::IsFinished(){
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

void AutoShootLowGoalReachArm::End(){
	//This method is run when the command is ended
	//Nothing happens
	//Except it does stop the arm from rotating anymore once in position
	Robot::ballmanipulator->RotateArm(0); //Stops the arm at the correct position
}

void AutoShootLowGoalReachArm::Interrupted(){
	//This method runs when the command is interrupted
	End(); //Ends the command
}
