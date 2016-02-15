#include "WPILib.h"
#include "Robot.h"
#include "Commands/Autonomous/Test Auto/TestAuto.h"
#include "Commands/Autonomous/Five Feet/AutoFiveFeet.h"
#include "Commands/Autonomous/Ten Feet/AutoTenFeet.h"
#include "Commands/Autonomous/Fifteen Feet/AutoFifteenFeet.h"
#include "Commands/Autonomous/Twenty Feet/AutoTwentyFeet.h"
#include "Commands/Autonomous/Turn Robot/AutoTurnRobot.h"

OI * Robot::oi = NULL;
DriveBase * Robot::drivebase = NULL;
Climber * Robot::climber = NULL;
BallManipulator * Robot::ballmanipulator = NULL;
Camera * Robot::camera = NULL;

void Robot::RobotInit(){
	oi = new OI();
	drivebase = new DriveBase();
	climber = new Climber();
	ballmanipulator = new BallManipulator();
	camera = new Camera();

	lw = LiveWindow::GetInstance();
	
	auto_choice = new SendableChooser();
	auto_choice->AddDefault("1 - TestAuto", new TestAuto(1000));
	auto_choice->AddObject("2 - FiveFeet", new AutoFiveFeet());
	auto_choice->AddObject("3 - TenFeet", new AutoTenFeet());
	auto_choice->AddObject("4 - FifteenFeet", new AutoFifteenFeet());
	auto_choice->AddObject("5 - TwentyFeet", new AutoTwentyFeet());
	auto_choice->AddObject("6 - TurnRobot", new AutoTurnRobot());
	SmartDashboard::PutData("Autonomous Mode", auto_choice);
	CameraServer::GetInstance()->SetQuality(50);
	CameraServer::GetInstance()->StartAutomaticCapture("cam0");
	auto_command = new TestAuto(1000);
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
