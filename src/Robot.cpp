//This is the main class for the robot
//It contains the objects for each Subsystem
//It also includes each method for Autonomous, TeleOp, and Test
//We've never used Test so I dunno if this is all that needs to be done for it to work
//Anyways
//We have four subsystems:
//OI (not a conventional subsystem, actually, it's not a subsystem, it's an OI), DriveBase, Climber, and BallManipulator
//We also use a SendableChooser to select from an array of Autos from the SmartDashboard
//Finally, we have a camera that is run here
#include "WPILib.h" //Includes the WPI Library for the robot
#include "Robot.h" //Includes the header file for this class
//Include the header files for each autonomous that can be selected
#include "Commands/Autonomous/Auto Cross Defense/AutoCrossDefense.h" //Includes the header file for TestAuto

OI * Robot::oi = NULL; //Sets the OI object to NULL
DriveBase * Robot::drivebase = NULL; //Sets the DriveBase object to NULL
Climber * Robot::climber = NULL; //Sets the Climber object to NULL
BallManipulator * Robot::ballmanipulator = NULL; //Sets the BallManipulator object to NULL

void Robot::RobotInit(){
	oi = new OI(); //Instantiates the OI object
	drivebase = new DriveBase(); //Instantiates the DriveBase object
	climber = new Climber(); //Instantiates the Climber object
	ballmanipulator = new BallManipulator(); //Instantiates the BallManipulator object

	lw = LiveWindow::GetInstance(); //Instantiates the LiveWindow object
	
	auto_choice = new SendableChooser(); //Instantiates the SendableChooser object
	auto_choice->AddDefault("1 - AutoCrossDefense", new AutoCrossDefense()); //Adds the default Autonomous to the SendableChooser
	SmartDashboard::PutData("Autonomous Mode", auto_choice); //Puts all of the Autonomous choices on the SmartDashboard
	CameraServer::GetInstance()->SetQuality(50); //Sets the quality of the Camera image to 50
	CameraServer::GetInstance()->StartAutomaticCapture("cam0"); //Starts the Camera
}

void Robot::AutonomousInit(){
	//This is the method that runs when Autonomous is initialized
	auto_command = (Command *) auto_choice->GetSelected(); //Sets the auto_command to whichever Autonomous is chosen on the SmartDashboard
	auto_command->Start(); //Starts the Autonomous that was chosen through the SmartDashboard
}

void Robot::AutonomousPeriodic(){
	//This is the method that runs periodically during Autonomous
	Scheduler::GetInstance()->Run(); //Runs the scheduler during Autonomous
}

void Robot::TeleopInit(){
	//This is the method that runs when TeleOp is initialized
	auto_command->Cancel(); //Cancels the Autonomous Command
}

void Robot::TeleopPeriodic(){
	//This is the method that runs periodically during TeleOp
	Scheduler::GetInstance()->Run(); //Runs the scheduler during TeleOp
}

void Robot::TestPeriodic(){
	//This is the method that runs periodically during Test
	lw->Run(); //Runs the LiveWindow during Test
}

START_ROBOT_CLASS(Robot); //Starts the robot class, which for us is "Robot"
