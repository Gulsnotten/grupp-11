#include "FPS_Limiter.h"



FPS_Limiter::FPS_Limiter()
{
	_lastTick = 0;
}


FPS_Limiter::~FPS_Limiter()
{
}

void FPS_Limiter::Delay(int fps) {
	int target = 1000 / fps;

	Uint32 currentTick = SDL_GetTicks();
	int wait = target - (currentTick - _lastTick);

	if (wait > 0) {
		SDL_Delay(wait);
	}

	_lastTick = currentTick;
}