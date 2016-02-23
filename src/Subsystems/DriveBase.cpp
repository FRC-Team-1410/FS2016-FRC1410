//This is the class for our DriveBase Subsystem
//Our DriveBase does exactly one thing
//It drives our robot both in TeleOp and Auto
//Which is technically doing two things
//Although it is also doing one thing in two places so yeah
//It does one thing
//Anyways it has the following motors:
//fl_motor, fr_motor, bl_motor, and br_motor
//They are the front left, front right, back left, and back right motors respectively
//Our robot doesn't really have front or back motors though
//So as long as both left motors are plugged into the left controllers and right into righ, it works
//There are also two encoders plugged into the fl_motor and fr_motor
//They are used for Autonomously driving a set distance
//There is also an AnalogGyro used for turning the robot
//Surprisingly, the robot drives straight worse when using the gyro than when not
//Because of this, the gyro is only used for turning
//It is unknown why this is, but it is, so that's how the robot works
#include <Commands/Drive Base/TeleOpDriveRobot.h> //Includes the default command
#include "Robot.h" //This includes Robot.h and I can't remember why but I'm too scared to remove it
#include "../RobotMap.h" //This includes the RobotMap.h which holds all the constants
#include "DriveBase.h" //Includes the header file for this class

DriveBase::DriveBase() : Subsystem("DriveBase"){
	fl_motor = new CANTalon(frontLeftDrive); //CAN ID 1
	fr_motor = new CANTalon(frontRightDrive); //CAN ID 2
	bl_motor = new CANTalon(backLeftDrive); //CAN ID 3
	br_motor = new CANTalon(backRightDrive); //CAN ID 4

	drive_gyro = new AnalogGyro(autoDriveGyro); //Analog Port 0
	drive_gyro->Calibrate(); //Calibrates the gyro (needed to use gyro accurately)
	drive_gyro->SetSensitivity(0.007); //Sets the sensitivity of the gyro (needed to use gyro accurately)

	fl_motor->SetFeedbackDevice(CANTalon::QuadEncoder); //Tells the Talon SRX that there is a Quadrature Encoder (needed to use encoder)
	fr_motor->SetFeedbackDevice(CANTalon::QuadEncoder); //Tells the Talon SRX that there is a Quadrature Encoder (needed to use encoder)

	prefs = Preferences::GetInstance(); //Initializes the Preferences object in this class (needed to use the preferences)
}

void DriveBase::InitDefaultCommand(){
	//This method sets a default command that starts to run when TeleOp is enabled
	//It makes it so that the command does not need to be called to drive the robot
	SetDefaultCommand(new TeleOpDriveRobot()); //Sets the default command to TeleOpDriveRobot
}

void DriveBase::DriveTank(float left_speed, float right_speed){
	//This method drives each side of the robot using set values
	//The values are not changed in any way
	//Since the right motors are opposite of the left motors, their values are inverted in the command
	//Because of this, when the speeds are output to the SmartDashboard we invert the inverted value
	fl_motor->Set(left_speed); //Sets the front left motor to the left speed
	fr_motor->Set(right_speed); //Sets the front right motor to the right speed
	bl_motor->Set(left_speed); //Sets the back left motor to the left speed
	br_motor->Set(right_speed); //Sets the back right motor to the right speed
	SmartDashboard::PutNumber("Left Speed", left_speed); //Puts the left speed on SmartDashboard
	SmartDashboard::PutNumber("Right Speed", right_speed * -1); //Puts the inverted right speed on SmartDashboard
}

void DriveBase::DriveExponential(float l, float r){
	//This method drives the robot in tank mode, but with an exponential curve
	//That is, the style of driving is tank mode (each side is driven by one stick)
	//But the values input into the method are then changed based on an exponential curve
	//This makes it so that the robot is easier to drive
	//Okay, technically none of these are exponential functions
	//This is because the process for including math.h in here was way too much work
	//Well not that much work
	//But too much for me to want to do it
	//Also, these functions work well enough
	//So here is our polynomial drive.
	float left_exponential; //This will become the value sent to the left motors
	float right_exponential; //This will become the value sent to the right motors
	int exponential_mode = prefs->GetInt("ExponentialMode", 1); //Retrieves the selected mode from the SmartDashboard preferences

	if(exponential_mode == 1){
		//This is exponential mode 1
		//It is vanilla tank mode
		//That is, the function is linear
		left_exponential = l; //Sets the left motor speed to the left input
		right_exponential = r; //Sets the right motor speed to the right input
	}
	else if(exponential_mode == 2){
		//This is exponential mode 2
		//It is a simple curve
		//That is, each value put in is then cubed
		//We use cubed because if it was squared it would never send negative values to the motors
		left_exponential = l * l * l; //Sets the left motor speed to (left input)^3
		right_exponential = r * r * r; //Sets the right motor speed to (right input)^3
	}
	else if(exponential_mode == 3){
		//This is exponential mode 3
		//It is a more complicated curve
		//That is, the average of the value plus the value cubed is found
		left_exponential = (l + (l * l * l)) / 2; //Sets the left motor speed to the average of left input + (left input)^3
		right_exponential = (r + (r * r * r)) / 2; //Sets the right motor speed to the average of right input + (right input)^3
	}
	else if(exponential_mode == 4){
		//This is exponential mode 4
		//It is the most complicated curve here
		//That is, the average of the value plus the value cubed plus the value to the fifth power is found
		left_exponential = (l + (l * l * l) + (l * l * l * l * l)) / 3; //Sets the left motor speed to the average of the left input + (left input)^3 + (left input)^5
		right_exponential = (r + (r * r * r) + (r * r * r * r * r)) / 3; //Sets the right motor speed to the average of the right input + (right input)^3 + (right input)^5
	}
	else{
		//This is the default exponential mode
		//It is only selected if the value input in the SmartDashboard is not 1, 2, 3, or 4
		//It is a linear function
		left_exponential = l;
		right_exponential = r;
	}
	SmartDashboard::PutNumber("Left Speed", left_exponential); //Puts the left exponential speed onto the SmartDashboard
	SmartDashboard::PutNumber("Right Speed", right_exponential); //Puts the right exponential speed onto the SmartDashboard
	fl_motor->Set(left_exponential); //Sets the front left motor to the left exponential speed
	fr_motor->Set(right_exponential); //Sets the front right motor to the right exponential speed
	bl_motor->Set(left_exponential); //Sets the back left motor to the left exponential speed
	br_motor->Set(right_exponential); //Sets the back right motor to the right exponential speed
}

float DriveBase::ReturnEncoderDistance(float left_encoder, float right_encoder, float distance){
	//This method returns the amount of encoder ticks driven by the robot
	//For the 2016 robot it is about 1000 ticks per foot
	//We are not converting ticks to feet because it is not accurate enough
	//And the awesome grip of our wheels means each foot we drive raises the ticks per foot
	left_encoder = fl_motor->GetEncPosition(); //Retrieves the value of the left encoder
	right_encoder = fr_motor->GetEncPosition() * -1; //Retrieves the value of the right encoder and inverts it

	distance = (left_encoder + right_encoder) / 2; //Averages the values from both encoders
	SmartDashboard::PutNumber("Encoder Distance", distance); //Places the average encoder distance in SmartDashboard
	SmartDashboard::PutNumber("Left Encoder", left_encoder); //Places the left encoder distance in SmartDashboard
	SmartDashboard::PutNumber("Right Encoder", right_encoder); //Places the right encoder distance in the SmartDashboard
	return distance; //Returns the average encoder distance
}

void DriveBase::ResetEncoderPosition(){
	//This method resets the position of each encoder
	//There isn't a way to do this besides setting the position to zero
	//So that's what we do
	SmartDashboard::PutNumber("Encoder Distance", 0); //Puts the reset encoder distance on the SmartDashboard
	fl_motor->SetPosition(0); //Sets the position of the front left motor to zero
	fr_motor->SetPosition(0); //Sets the position of the front right motor to zero
}

float DriveBase::ReturnGyroPosition(){
	//This method returns the angle of the gyro
	//It is used for turning
	//I believe that the AnalogGyro method we use returns a value in degrees
	//I mean, when we turned 1/4 of a circle, it said 90
	//Therefore, it returns in degrees
	SmartDashboard::PutNumber("Gyro Angle", drive_gyro->GetAngle()); //Puts the gyro angle on the SmartDashboard
	return drive_gyro->GetAngle(); //Returns the angle recieved from the gyro in degrees (I think)
}

void DriveBase::ResetGyro(){
	//This method resets the gyro
	//What that does is if I face East, that direction is now 0 degrees
	//Then if I turn to the South, I have moved 90 degrees from East
	SmartDashboard::PutNumber("Gyro Angle", 0); //Puts zero where it says "Gyro Angle" on the SmartDashboard
	drive_gyro->Reset(); //Resets the gyro by using the AnalogGyro method Reset()
}

void DriveBase::CalibrateGyro(){
	//This method calibrates the gyro
	//I can't tell if it ever helps
	//But it seems to
	//We don't use it though
	drive_gyro->Calibrate(); //Calibrates the gyro by calling the AnalogGyro method Calibrate()
}
