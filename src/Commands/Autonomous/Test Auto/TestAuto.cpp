#include "TestAuto.h"
#include "Test Auto Commands/TestAutoDriveStraight.h"
TestAuto::TestAuto(){
	AddSequential(new TestAutoDriveStraight());
}
