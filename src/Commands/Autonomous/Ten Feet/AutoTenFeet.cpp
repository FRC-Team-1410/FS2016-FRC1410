#include "AutoTenFeet.h"
#include "../Test Auto/TestAuto.h"

AutoTenFeet::AutoTenFeet(){
	AddSequential(new TestAuto(10000));
}
