#ifndef MY_ROBOT_H_
#define MY_ROBOT_H_

#include "WPILib.h"

#include "OI.h" //Includes header file for the OI
#include "Subsystems/DriveBase.h" //Includes header file for the DriveBase Subsystem
#include "Subsystems/Climber.h" //Includes header file for the Climber Subsystem
#include "Subsystems/BallManipulator.h" //Includes header file for the BallManipulator Subsystem

class Robot: public IterativeRobot {
public:
	//Declare objects for each Subsystem below
	static OI * oi; //Static OI object
	static DriveBase * drivebase; //Static DriveBase Subsystem object
	static Climber * climber; //Static Climber Subsystem object
	static BallManipulator * ballmanipulator; //Static BallManipulator Subsystem object

private:
	LiveWindow * lw; //LiveWindow object, dunno what this for
	Command * auto_command; //Command object for autonomous
	SendableChooser * auto_choice; //SendableChooser object to choose autonomous from the SmartDashboard

	void RobotInit();
	void AutonomousInit();
	void AutonomousPeriodic();
	void TeleopInit();
	void TeleopPeriodic();
	void TestPeriodic();
};

#endif
