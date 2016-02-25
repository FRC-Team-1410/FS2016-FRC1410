#include <Commands/Autonomous/Auto Cross Defense/Auto Cross Defense Command Groups/AutoCrossDefenseDrive.h>
#include "Auto Cross Defense Drive Commands/AutoCrossDefenseDriveStraight.h"

AutoCrossDefenseDrive::AutoCrossDefenseDrive(){
	AddParallel(new AutoCrossDefenseDriveStraight());
}
