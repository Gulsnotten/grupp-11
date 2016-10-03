#pragma once
struct SDL_Renderer;
struct SDL_Color;
struct SDL_Rect;
class Window;

class Renderer
{
	SDL_Renderer* _ptr;
	Renderer(Renderer&) = delete;                //disable copy constructor
	Renderer& operator=(Renderer&) = delete;     //disable copy assignment

public:
	Renderer(const Window& w);
	~Renderer();
	void clear() const;
	void setColor(const SDL_Color& c) const;
	void drawRect(const SDL_Rect& r) const;
	void present() const;
};

