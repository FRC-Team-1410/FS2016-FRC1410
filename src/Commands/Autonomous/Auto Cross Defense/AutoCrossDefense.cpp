#include "AutoCrossDefense.h"
#include "Auto Cross Defense Command Groups/AutoCrossDefenseDrive.h"

AutoCrossDefense::AutoCrossDefense(){
	AddSequential(new AutoCrossDefenseDrive());
}
