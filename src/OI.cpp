//This is the OI or Operator Interface
//It is where we declare the Joysticks and JoystickButtons
//Also where we declare what each button does
#include "OI.h" //Includes the header file for this class
#include "RobotMap.h" //Includes RobotMap.h which has all the constants we've set
#include "Commands/Ball Manipulator/TeleOpMoveArm.h" //Includes the command to move the arm
#include "Commands/Ball Manipulator/TeleOpRollersInwards.h" //Includes the command to spin the rollers inwards
#include "Commands/Ball Manipulator/TeleOpRollersOutwards.h" //Includes the command to spin the rollers outwards
#include "Commands/Climber/TeleOpActuateServo.h" //Includes the command to actuate the servo in the climber
#include "Commands/Climber/TeleOpClimb.h" //Includes the command to both rotate the climber and winch the climber
#include "Commands/Climber/TeleOpRotateClimber.h" //Includes the command to rotate the climber
#include "Commands/Climber/TeleOpWinchClimber.h" //Includes the command to winch the climber
#include "Commands/Drive Base/TeleOpDriveRobot.h" //Includes the command to drive the robot

//The following array is to create a deadband in the controllers
const char inputShape[255] = {0,1,3,4,5,6,7,9,10,11,12,13,15,16,17,18,19,21,22,23,24,25,27,28,29,30,31,
 	        33,34,35,36,37,38,40,41,42,43,44,46,47,48,49,50,52,53,54,55,56,58,59,60,61,62,
 	        64,65,66,67,68,70,71,72,73,74,76,77,78,79,80,82,83,84,85,86,88,89,90,91,92,94,
 	        95,96,97,98,100,101,102,103,104,106,107,108,109,110,112,113,114,115,116,117,
 	        118,119,120,121,121,122,123,123,124,124,125,125,125,126,126,126,126,126,127,
 	        127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,127,
 	        128,128,128,128,128,129,129,129,130,130,131,131,132,133,133,134,135,136,
 	        137,138,139,140,141,142,144,145,146,147,148,150,151,152,153,154,156,157,158,
 	        159,160,162,163,164,165,166,168,169,170,171,172,174,175,176,177,178,180,181,
 	        182,183,184,186,187,188,189,190,192,193,194,195,196,198,199,200,201,202,204,
 	        205,206,207,208,210,211,212,213,214,216,217,218,219,220,221,223,224,225,226,
 	        227,229,230,231,232,233,235,236,237,238,239,241,242,243,244,245,247,248,249,
 	        250,251,253,254,255};

//The following function is what uses the deadband
float InputShape(float userValue){
	int iUserValue; //Creates the iUserValue integer


	iUserValue = (int)(userValue * 127); //Multiplies the input value by 127 and converts it to an int
	iUserValue += 127; //Adds 127 to the value of iUserValue
	iUserValue = inputShape[iUserValue]; //Sets iUserValue to the value in the spot of the array that has the address equal to iUserValue
	userValue = iUserValue - 127; //Sets userValue to iUserValue minue 127
	userValue /= 127; //Divides userValue by 127
	return userValue; //Returns userValue which is a float, not an int
}

OI::OI(){
	driver_stick = new Joystick(driverStickPort); //Stick port 0
	operator_stick = new Joystick(operatorStickPort); //Stick port 1
	climber_stick = new Joystick(climberStickPort); //Stick port 2

	prefs = Preferences::GetInstance(); //Initializes prefs object in this class

	rollers_in = new JoystickButton(operator_stick, rollersInButton); //A button (button 1)
	rollers_out = new JoystickButton(operator_stick, rollersOutButton); //B button (button 2)
	winch_climber = new JoystickButton(climber_stick, winchClimberButton); //Back button on handle (button 2)
	unwinch_climber = new JoystickButton(climber_stick, unwinchClimberButton); //Front button on handle (button 3)
	rotate_climber = new JoystickButton(climber_stick, rotateClimberButton); //Trigger on the handle (button 1)
	lock_gear = new JoystickButton(climber_stick, lockGearButton); //Left button on the base of the joystick (button 8)
	unlock_gear = new JoystickButton(climber_stick, unlockGearButton); //Right button on the base of the joystick (button 9)

	rollers_in->ToggleWhenPressed(new TeleOpRollersInwards()); //Toggles the rollers inwards when button is pressed
	rollers_out->ToggleWhenPressed(new TeleOpRollersOutwards()); //Toggles the rollers outwards when button is pressed
	winch_climber->WhileHeld(new TeleOpClimb(-1)); //While held the climber is winched in and can be rotated
	unwinch_climber->WhileHeld(new TeleOpClimb(1)); //While held the climber is winched out and can be rotated
	rotate_climber->WhileHeld(new TeleOpRotateClimber()); //While held the climber is not winched and can be rotated
	lock_gear->ToggleWhenPressed(new TeleOpActuateServo(0.4)); //Toggles the servo towards the gear when button is pressed
	unlock_gear->ToggleWhenPressed(new TeleOpActuateServo(0.75)); //Toggles the servo away from the gear when button is pressed
}

double OI::GetDriveAxis(int axis){
	//This method returns a raw axis from driver_stick put through the deadband
	//The multiplier can speed up or slow down the driving of the robot
	float drive_multiplier = prefs->GetFloat("DriveMultiplier", 1.0); //Retrieves the multiplier from SmartDashboard
	SmartDashboard::PutNumber("DriveMultiplier", drive_multiplier); //Puts the value of the multiplier on the SmartDashboard
	return (InputShape((float)driver_stick->GetRawAxis(axis) * drive_multiplier)); //Returns the value from the driver stick axis times the multiplier, then put through InputShape
}

double OI::GetOperatorAxis(int axis){
	//This method returns the raw axis from operator_stick put through the deadband
	return InputShape((float)operator_stick->GetRawAxis(axis)); //Returns the value of the operator stick put through InputShape
}

double OI::GetClimberAxis(int axis){
	//This method returns the raw axis from climber_stick put through the deadband
	return InputShape((float)climber_stick->GetRawAxis(axis)); //Returns the value of the climber stick put through InputShape
}
