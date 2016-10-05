/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#pragma once
#include "SDL.h"
class FPS_Limiter
{
	Uint32 _lastTick;
public:
	FPS_Limiter();
	~FPS_Limiter();

	void Delay(const int delay);
};

