#pragma once
#include <vector>
#include "Config.h"
#include "SDLSystem.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Window.h"
#include <memory>
class Entity;
class Paddle;
class Ball;
class Brick;

class ArkanoidGame
{
	void readInput();
	void update();
	void render();
	void cleanup();
	void checkWin();
	void createEntities();
	void destroyEntities();

	SDLSystem _sdl;
	Window _window;
	Renderer _r{ _window };
	InputManager _input;
	std::shared_ptr<Paddle> _paddle;
	std::shared_ptr<Ball> _ball;
	std::vector<std::shared_ptr<Entity>> _entities;

public:
	ArkanoidGame();
	~ArkanoidGame();
	void run();
};

