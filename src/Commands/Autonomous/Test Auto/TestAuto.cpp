#include "TestAuto.h"
#include "Test Auto Commands/TestAutoDriveStraight.h"
TestAuto::TestAuto(float distance){
	AddSequential(new TestAutoDriveStraight(distance));
}
