#include "InputManager.h"
#include <stdexcept>
#include "SDLSystem.h"
#include <iostream>
#include <cassert>

InputManager::InputManager() : _keyStates(SDL_GetKeyboardState(nullptr)), _clickedClosedButton(false), _mousePosition{0, 0}
{
	if (!_keyStates) {
		throw std::runtime_error(SDL_GetError());
	}
}


InputManager::~InputManager()
{
}

void InputManager::update()
{
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
		if (e.type == SDL_QUIT) {
			_clickedClosedButton = true;
		}
		else if (e.type == SDL_MOUSEMOTION) {
			onMouseMove(e.motion);
		}
		else if (e.type == SDL_MOUSEBUTTONUP) {
			onMouseButtonUp(e.button);
		}
		else if (e.type == SDL_MOUSEBUTTONDOWN) {
			onMouseButtonDown(e.button);
		}
		else if (e.type == SDL_KEYUP) {
			onKeyUp(e.key);
		}
		else if (e.type == SDL_KEYDOWN) {
			onKeyDown(e.key);
		}
	}
}

bool InputManager::isKeyDown(const SDL_Scancode key)
{
	return (_keyStates[key] == 1);
}

bool InputManager::isButtonDown(Button b)
{
	return _buttonStates.at(b) == true;
}

bool InputManager::quitRequested()
{
	return _clickedClosedButton || isKeyDown(SDL_SCANCODE_ESCAPE);
}

int InputManager::mouseX()
{
	return _mousePosition.x;
}

int InputManager::mouseY()
{
	return _mousePosition.y;
}

void InputManager::onKeyDown(const SDL_KeyboardEvent & e)
{
}

void InputManager::onKeyUp(const SDL_KeyboardEvent & e)
{
}

void InputManager::onMouseMove(SDL_MouseMotionEvent & e)
{
	_mousePosition.x = e.x;
	_mousePosition.y = e.y;
}

void InputManager::onMouseButtonUp(SDL_MouseButtonEvent & e)
{
	_buttonStates[e.button] = false;
}

void InputManager::onMouseButtonDown(SDL_MouseButtonEvent & e)
{
	_buttonStates[e.button] = true;
}
