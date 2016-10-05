/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#pragma once
#include "SDL.h"

class SDLSystem
{
	Uint32 _flags;
public:
	SDLSystem(Uint32 flags = SDL_INIT_VIDEO);
	~SDLSystem();
	bool isUp(Uint32 flags = 0);
};

