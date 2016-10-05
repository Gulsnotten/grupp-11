#pragma once
#include <vector>
#include "Config.h"
#include "SDLSystem.h"
#include "Renderer.h"
#include "InputManager.h"
#include "Window.h"
#include "FPS_Limiter.h"
#include "GameSession.h"
#include "GameMessage.h"
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

	void nextRound();
	void roundOver();
	void startGame();
	GameSession gameSession;
	GameMessage gameMessage;

	SDLSystem _sdl;
	Window _window;
	Renderer _r{ _window };
	InputManager _input;
	FPS_Limiter fps;
	std::shared_ptr<Paddle> _paddle;
	std::shared_ptr<Ball> _ball;
	std::vector<std::shared_ptr<Entity>> _entities;
public:
	ArkanoidGame();
	~ArkanoidGame();
	void run();
};

