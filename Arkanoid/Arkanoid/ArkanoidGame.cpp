#include "ArkanoidGame.h"
#include "Random.h"
#include "Config.h"
#include "Paddle.h"
#include "Ball.h"
#include "Brick.h"
#include <algorithm>
//using namespace Config;

ArkanoidGame::ArkanoidGame() : _window { Config::TITLE, Config::WIN_WIDTH, Config::WIN_HEIGHT }, _paddle{ nullptr }, _ball{ nullptr }
{
	createEntities();
}

ArkanoidGame::~ArkanoidGame()
{
	try {
		destroyEntities();
	}catch (...) {}
}

void ArkanoidGame::createEntities()
{
	destroyEntities();
	float halfPaddle = (Config::PADDLE_WIDTH / 2);
	_paddle = std::make_shared<Paddle>(Config::CENTER_X - halfPaddle, Config::WIN_HEIGHT-100.0f);
	_ball = std::make_shared<Ball>(0.0f, 0.0f);
	_ball->_x = _paddle->centerX() - _ball->halfWidth();
	_ball->_y = _paddle->top() - _ball->_height;
	for (int i = 1; i < Config::COLUMNS; i++) {
		float x = i*(Config::BRICK_WIDTH + Config::PADDING);
		for (int j = 1; j < Config::ROWS; j++) {
			float y = j*(Config::BRICK_HEIGHT + Config::PADDING);
			_entities.push_back(std::make_shared<Brick>(x, y));
		}
	}
	_entities.push_back(_paddle);
	_entities.push_back(_ball);
	//detta borde flyttas till en class
}

void ArkanoidGame::destroyEntities()
{
	_paddle.reset();
	_ball.reset();
	_entities.clear();
}

void ArkanoidGame::run()
{
	int frameStart = 0;
	int frameTime = 0;
	int frameCount = 0;
	unsigned int nextTime = SDL_GetTicks() + Config::SAMPLE_INTERVAL;
	while (!_input.quitRequested()) {
		frameStart = SDL_GetTicks();
		readInput();
		update();
		render();
		cleanup();
		checkWin();
		frameTime = SDL_GetTicks() - frameStart;
		if (frameTime < Config::DELAY_TIME) {
			SDL_Delay(Config::DELAY_TIME - frameTime);
		}
		frameCount++;
		if (nextTime < SDL_GetTicks()) {
			frameCount = frameCount / (Config::SAMPLE_INTERVAL / 1000);
			std::string fps{ Config::TITLE + " FPS: " + std::to_string(frameCount) };
			SDL_SetWindowTitle(_window.getPointer(), fps.c_str());
			frameCount = 0;
			nextTime = SDL_GetTicks() + Config::SAMPLE_INTERVAL;
		}
		// Den här FPS grejen måste flyttas till en separat class
	}
}

void ArkanoidGame::update()
{
	for (auto e : _entities) {
		e->update();
		if (e == _ball) continue;
		if (isColliding(*_ball, *e)) {
			e->onCollision(*_ball);
			_ball->onCollision(*e);
		}
	}
}

void ArkanoidGame::checkWin() {
	if (_ball->_y > (_paddle)->_y + _paddle->_height) {
		destroyEntities();
		createEntities();
	}
}

void ArkanoidGame::render()
{
	_r.setColor(Config::BG_COLOR);
	_r.clear();
	SDL_Rect rect;
	for (auto e : _entities) {
		_r.setColor(e->_color);
		e->getBounds(rect);
		_r.drawRect(rect);
	}
	_r.present();
}

void ArkanoidGame::cleanup()
{
	for (int i = _entities.size() - 1; i >= 0; i--) {
		if (_entities[i]->_isDead) {
			//_entities.erase(_entities.begin() + i);  <- långsammare
			std::swap(_entities[i], _entities.back());
			_entities.pop_back();
		}
	}
}

void ArkanoidGame::readInput() {
	_input.update();
	if (_ball->_hasLaunched) {
		_paddle->onMouseMove(_input.mouseX(), _input.mouseY());
	}
	else {
		if (_input.isButtonDown(LEFT) || _input.isKeyDown(SDL_SCANCODE_SPACE)) {
			_ball->launch();
		}
	}
}




