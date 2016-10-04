#pragma once
#include "SDLSystem.h"
#include "Config.h"
class FPS_Limiter
{
	Uint32 _lastTick;
public:
	FPS_Limiter();
	~FPS_Limiter();

	void Delay(const int delay);
};