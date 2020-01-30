#pragma once
#include "SDL.h"
#include <string>

class Window
{
public:
	Window(std::string const& title, int width, int height);
	~Window();

	void Init();

	SDL_Window* GetWindow() { return this->window; }
	SDL_Renderer* GetRenderer() { return this->screenRenderer; }

private:
	SDL_Window* window;
	SDL_Renderer* screenRenderer;

	int screenWidth;
	int screenHeight;

	std::string screenTitle;
};

