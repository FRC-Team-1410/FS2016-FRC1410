#include "AutoTwentyFeet.h"
#include "../Test Auto/TestAuto.h"

AutoTwentyFeet::AutoTwentyFeet(){
	AddSequential(new TestAuto(20000));
}
