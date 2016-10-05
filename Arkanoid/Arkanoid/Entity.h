/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#pragma once
#include "SDLSystem.h"

class Entity
{
public:
	float _x;
	float _y;
	float _vx;
	float _vy;
	int _width;
	int _height;
	float centerX() const;
	float centerY() const;
	float left() const;
	float right() const;
	float top() const;
	float bottom() const;
	int halfWidth() const;
	int halfHeight() const;

	bool _isDead;
	SDL_Color _color;

	virtual void update();
	virtual void onCollision(const Entity& that);
	void getBounds(SDL_Rect& r) const;

	virtual int getScore();

	Entity(float x, float y, int width, int height);
	virtual ~Entity();
};

bool isColliding(const Entity& lhs, const Entity& rhs);
bool getOverlap(const Entity& lhs, const Entity& rhs, int& overlapX, int& overlapY);

