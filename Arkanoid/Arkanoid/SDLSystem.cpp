/*
Team 11
Alexander Granell & Erik S�ll
10/6/2016
*/

#include "SDLSystem.h"
#include <stdexcept>


SDLSystem::SDLSystem(Uint32 flags)
{
	if (SDL_Init(flags) != 0) {
		throw std::runtime_error(SDL_GetError());
	}
	_flags = flags;
}


SDLSystem::~SDLSystem()
{
	SDL_Quit();
}

bool SDLSystem::isUp(Uint32 flags)
{
	if (flags == 0) {
		flags = _flags;
	}
	return SDL_WasInit(flags) != 0;
}
