//This is the CommandGroup that is used to drive the rotation motor and winch motor at the same time
//We have to do this so we can rotate the robot and winch at the same time
//The reason that we don't just do this with a single command is because
//If we did, then as long as we were winching or unwinching the robot,
//We would continually rotate the climber
//The float speed in the constructor is to pass on to the TeleOpWinchClimber
#include "TeleOpClimb.h" //Includes the header file for the class
#include <Commands/Climber/TeleOpRotateClimber.h> //Includes the command that rotates the climber
#include "TeleOpWinchClimber.h" //Includes the command that winches the climber

TeleOpClimb::TeleOpClimb(float speed){
	//Both commands below run parallel to each other
	AddParallel(new TeleOpRotateClimber()); //Adds the command to rotate the climber
	AddParallel(new TeleOpWinchClimber(speed)); //Adds the command to winch the climber and inserts speed into the command
}
