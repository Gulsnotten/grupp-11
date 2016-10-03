#pragma once
#include "SDLSystem.h"
#include <array>

enum Button {
	LEFT = SDL_BUTTON_LEFT,
    MIDDLE = SDL_BUTTON_MIDDLE,
    RIGHT = SDL_BUTTON_RIGHT,
    X1 = SDL_BUTTON_X1,
    X2 = SDL_BUTTON_X2,
};

class InputManager
{
	InputManager(const InputManager&) = delete;
	InputManager& operator=(InputManager&) = delete;

	void onKeyDown(const SDL_KeyboardEvent& e);
	void onKeyUp(const SDL_KeyboardEvent& e);
	void onMouseMove(SDL_MouseMotionEvent& e);
	void onMouseButtonUp(SDL_MouseButtonEvent& e);
	void onMouseButtonDown(SDL_MouseButtonEvent& e);

	const Uint8* _keyStates;
	std::array<bool, 6> _buttonStates;
	bool _clickedClosedButton;
	SDL_Point _mousePosition;

public:
	InputManager();
	~InputManager();

	void update();
	bool isKeyDown(const SDL_Scancode key);
	bool isButtonDown(Button b);
	bool quitRequested();
	int mouseX();
	int mouseY();
};

