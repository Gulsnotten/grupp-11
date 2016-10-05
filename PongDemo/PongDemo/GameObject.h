/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#pragma once
#include "SDL.h"
class GameObject
{
protected:
	SDL_Rect rect;
public:
	GameObject();
	~GameObject();

	enum Side { left, right };
	SDL_Rect GetRect() const;

	virtual void update();
};

