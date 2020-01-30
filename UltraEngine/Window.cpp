#include "Window.h"

Window::Window(std::string const& title, int width, int height)
{
	this->screenWidth = width;
	this->screenHeight = height;
	this->screenTitle = title;
}

Window::~Window()
{
	SDL_DestroyRenderer(screenRenderer);
	SDL_DestroyWindow(window);
}

void Window::Init()
{
	window = SDL_CreateWindow(screenTitle.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, screenWidth, screenHeight, SDL_WINDOW_OPENGL);
	screenRenderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
}
