//This is our Climber Subsystem
//It has three motors
//left_rotation, right_rotation, and winch_motor
//They are the left and right rotation motors and the winch motor, respectively
//The left and right rotation motors move in the same direction
//The winch motor is what controls the rope we're using to pull our robot up
//There is also a servo that is used to jam into a gear in the gearbox
//This is because the robot starts to slowly fall down
//This servo will stop this from happening
//The climber has a limit switch at the bottom so that we don't slam it into the rest of the robot and keep on driving
//The winch has a limit switch that will stop the climber from winching in too much
#include "Robot.h" //Includes Robot.h but I don't know why so I won't remove it
#include "../RobotMap.h" //Includes RobotMap.h which stores all the constants
#include "Climber.h" //Includes the header file for the class

Climber::Climber() : Subsystem("Climber"){
	left_rotation = new CANTalon(leftClimberRotation); //CAN ID 5
	right_rotation = new CANTalon(rightClimberRotation); //CAN ID 7
	winch_motor = new CANTalon(leftClimberWinch); //CAN ID 8

	winch_servo = new Servo(climberServoPWM); //PWM port 0

	prefs = Preferences::GetInstance(); //Initializes the prefs object in this class
}

void Climber::InitDefaultCommand(){
	//There is no default command for this class
}

void Climber::RotateClimber(float speed){
	//This method rotates the climber
	//There is a multiplier to tone down the speed at which it rotates
	//The method sets both rotation motors to the same speed * multiplier
	float multiplier = prefs->GetFloat("ClimberRotateSpeed", 1); //Retrieves the multiplier from SmartDashboard (default is 1)
	SmartDashboard::PutNumber("Climber Speed", speed * multiplier); //Puts the speed of the climber on the SmartDashboard
	left_rotation->Set(speed * multiplier); //Sets left_rotation to speed * multiplier
	right_rotation->Set(speed * multiplier); //Sets right_rotation to speed * multiplier
}

void Climber::WinchClimber(float speed){
	//This method runs the winch on the climber
	//There is also a multiplier to tone down the winch's speed
	//This multiplier is pulled from the SmartDashboard
	//Sets the winch motor to speed * multiplier
	float multiplier = prefs->GetFloat("ClimberWinchSpeed", 1.0); //Retrieves the multiplier from SmartDashboard (default is 0.8)
	SmartDashboard::PutNumber("Winch Speed", speed * multiplier); //Puts the speed of the winch on to SmartDashboard
	winch_motor->Set(speed * multiplier); //Sets winch_motor to speed * multiplier
}

bool Climber::ReturnUpLimit(){
	//This method returns if the climber is at the upper limit
	//As of right now, there is no upper limit switch but it might be added later
	//The limit switch is the reverse one as the rotation motor drives negative, the reverse limit switch stops it
	//This method is not used to stop the motor, just check if it is at the limit
	SmartDashboard::PutBoolean("Upper Limit", left_rotation->IsRevLimitSwitchClosed()); //Indicates on the SmartDashboard if the upper limit is triggered
	return left_rotation->IsRevLimitSwitchClosed(); //Returns if the reverse limit switch is closed
}

bool Climber::ReturnDownLimit(){
	//This method returns if the climber is at the lower limit
	//The limit switch is the forward one as the rotation motor drives positive, the forward limit switch stops it
	//This method is not used to stop the motor, just check if it is at the limit
	SmartDashboard::PutBoolean("Lower Limit", left_rotation->IsFwdLimitSwitchClosed()); //Indicates on the SmartDashboard if the lower limit is triggered
	return left_rotation->IsFwdLimitSwitchClosed(); //Returns if the forward limit switch is closed
}

bool Climber::ReturnWinchLimit(){
	//This method returns if the climber is winched back completely
	//The limit switch is the reverse one as the winch motor drives negative to winch in the climber
	//This method is not used to stop the motor, just check if it as the limit
	//We need to check this limit so that the winch doesn't break something
	SmartDashboard::PutBoolean("Winch Limit", winch_motor->IsRevLimitSwitchClosed()); //Indicates on the SmartDashboard if the winch limit is triggered
	return winch_motor->IsRevLimitSwitchClosed(); //Returns if the reverse limit switch is closed
}

void Climber::MoveServo(float position){
	//This method moves the servo halfway around
	//It is used to stop the gear from spinning while the robot is hanging from the bar
	SmartDashboard::PutNumber("Servo Position", position); //Indicates on the SmartDashboard the position of the servo
	winch_servo->Set(position); //Sets the servo position to whatever position is, or (position * 100) % around the range of the servo
}
