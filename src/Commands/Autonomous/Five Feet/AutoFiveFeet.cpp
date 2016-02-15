#include "AutoFiveFeet.h"
#include "../Test Auto/TestAuto.h"

AutoFiveFeet::AutoFiveFeet(){
	AddSequential(new TestAuto(5000));
}
