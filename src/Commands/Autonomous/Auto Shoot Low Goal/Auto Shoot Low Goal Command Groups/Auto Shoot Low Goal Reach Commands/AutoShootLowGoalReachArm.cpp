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
	float speed = prefs->GetFloat("AutoshootLowGoalArmSpeed", -1); //Retrieves the speed for the arm from the SmartDashboard
	float angle = prefs->GetFloat("AutoShootLowGoalArmBackwards",  145); //Retrieves the angle to move the arm from the SmartDashboard
	float rollers = prefs->GetFloat("AutoShootLowGoalRollerSpeed", -0.75); //Retrieves the angle to move the arm from the SmartDashboard

	if(Robot::ballmanipulator->ReturnArmAngle() > angle){
		Robot::ballmanipulator->RotateArm(-speed);
		Robot::ballmanipulator->SetRollers(-rollers);
	}
	else{
		Robot::ballmanipulator->RotateArm(0);
		Robot::ballmanipulator->SetRollers(-rollers);
		End();
	}
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
	float angle = prefs->GetFloat("AutoShootLowGoalArmBackwards",  145); //Retrieves the angle to move the arm from the SmartDashboard
	return ((angle - 5) < Robot::ballmanipulator->ReturnArmAngle()) && (Robot::ballmanipulator->ReturnArmAngle() < (angle + 5));
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
