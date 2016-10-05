/*
Team 11
Alexander Granell & Erik Säll
10/6/2016
*/

#pragma once
#include "Entity.h"
#include "GameSession.h"

class Brick : public Entity
{
private:
	int _scoreValue;
	int _hitPoints;
	void setColor();
public:
	int getScore() override;

	void onCollision(const Entity& that);
	int getHitPoints() const;
	Brick(float x, float y);
	Brick(float x, float y, int hitPoints);
	~Brick();
};

