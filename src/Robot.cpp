#include "WPILib.h"
#include "Robot.h"
#include "Commands/Autonomous/Test Auto/TestAuto.h"
OI * Robot::oi = NULL;
DriveBase * Robot::drivebase = NULL;
Climber * Robot::climber = NULL;
BallManipulator * Robot::ballmanipulator = NULL;

void Robot::RobotInit(){
	oi = new OI();
	drivebase = new DriveBase();
	climber = new Climber();
	ballmanipulator = new BallManipulator();

	lw = LiveWindow::GetInstance();
	
	auto_choice = new SendableChooser();
	SmartDashboard::PutData("Autonomous Mode", auto_choice);
	auto_choice->AddDefault("TestAuto", new TestAuto());
	//CameraServer::GetInstance()->SetQuality(50);
	//CameraServer::GetInstance()->StartAutomaticCapture("cam0");
}

void Robot::AutonomousInit(){
	auto_command = (Command *) auto_choice->GetSelected();
	auto_command->Start();
}

void Robot::AutonomousPeriodic(){
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit(){
	auto_command->Cancel();
}

void Robot::TeleopPeriodic(){
	Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic(){
	lw->Run();
}

START_ROBOT_CLASS(Robot);
