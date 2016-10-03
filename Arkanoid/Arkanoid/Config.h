#pragma once
#include "SDLSystem.h"
#include <string>

namespace Config {
	static const SDL_Color BG_COLOR{ 0x00, 0x00, 0x00, 0xFF };
	static const SDL_Color FG_COLOR{ 0xFF, 0xFF, 0xFF, 0xFF };
	static const SDL_Color PADDLE_COLOR{ 0xFF, 0x00, 0xFF, 0xFF };
	static const SDL_Color BALL_COLOR{ 0xFF, 0x00, 0xFF, 0xFF };
	static const std::string TITLE = "Arkanoid";
	static const int WIN_WIDTH = 480;
	static const int CENTER_X = WIN_WIDTH / 2;
	static const int WIN_HEIGHT = 680;
	static const int BRICK_WIDTH = 30;
	static const int BRICK_HEIGHT = 15;
	static const int BALL_WIDTH = 15;
	static const int PADDLE_WIDTH = 100;
	static const int COLUMNS = 7;
	static const int ROWS = 5;
	static const float PADDING = 30.0f;
	static const float FRICTION = 0.98f;
	static const float EASING = 0.125f;
	static const int FPS = 60;
	static const int DELAY_TIME = 1000 / FPS;
	static const int SAMPLE_INTERVAL = 1000;
};