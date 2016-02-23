#include "TeleOpClimb.h"
#include "TeleOpToggleClimber.h"
#include "TeleOpWinchClimber.h"

TeleOpClimb::TeleOpClimb(float speed){
	AddParallel(new TeleOpToggleClimber());
	AddParallel(new TeleOpWinchClimber(speed));
}
