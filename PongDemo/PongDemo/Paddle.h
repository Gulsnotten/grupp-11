/*
Team 11
Alexander Granell & Erik S�ll
10/6/2016
*/

#pragma once
#include "Playfield.h"
#include "SDL.h"
#include "GameObject.h"

class Playfield;

class Paddle : public GameObject
{
	static const int SPEED = 8;

	bool pressingUp;
	bool pressingDown;

	Side side;
public:
	static const int WIDTH = 12;
	static const int HEIGHT = 64;

	Paddle();
	Paddle(Side side_);
	~Paddle();
	
	Side GetSide();

	void update() override;
	void checkBounds();
	void pressUp(bool b);
	void pressDown(bool b);
};

