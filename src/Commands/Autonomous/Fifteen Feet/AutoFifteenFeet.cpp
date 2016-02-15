#include "AutoFifteenFeet.h"
#include "../Test Auto/TestAuto.h"

AutoFifteenFeet::AutoFifteenFeet(){
	AddSequential(new TestAuto(15000));
}
