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

	int wait = target - (SDL_GetTicks() - _lastTick);

	if (wait > 0) {
		SDL_Delay(wait);
	}

	_lastTick = SDL_GetTicks();
}