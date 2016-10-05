/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#include "Renderer.h"
#include "SDLSystem.h"
#include <stdexcept>
#include "Config.h"
#include "Window.h"

Renderer::Renderer(const Window& w) : _ptr{ SDL_CreateRenderer(w.getPointer(), -1, SDL_RENDERER_ACCELERATED) }
{
	if (!_ptr) {
		throw std::runtime_error(SDL_GetError());
	}
}


Renderer::~Renderer()
{
	if (_ptr) {
		SDL_DestroyRenderer(_ptr);
	}
}

void Renderer::clear() const
{
	SDL_RenderClear(_ptr);
}

void Renderer::setColor(const SDL_Color& c) const
{
	SDL_SetRenderDrawColor(_ptr, c.r, c.g, c.b, c.a);
}

void Renderer::drawRect(const SDL_Rect& c) const
{
	SDL_RenderFillRect(_ptr, &c);
}

void Renderer::present() const
{
	SDL_RenderPresent(_ptr);
}
