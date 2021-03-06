/*
Team 11
Alexander Granell & Erik S�ll
10/6/2016
*/

#pragma once
#include "Config.h"
class GameSession
{
	int _lives;
	int _score;
public:
	GameSession();
	~GameSession();

	void looseLife();
	void reset();
	void addScore(const int points);
	bool isGameOver() const;
	int getLives() const;
	int getScore() const;
};

