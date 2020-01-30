#pragma once
#include "Ultralight/Ultralight.h"
#include "Window.h"

class Main
{
public:
	Main();
	~Main();

	void Update();
	void Draw(Window& window);
	void HandleInputs();

private:
	ultralight::RefPtr<ultralight::Renderer> renderer;
	ultralight::RefPtr<ultralight::View> view;

	SDL_Texture* ultraSurfaceTex = nullptr;
};

