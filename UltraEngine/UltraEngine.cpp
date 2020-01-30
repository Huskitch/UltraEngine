#include <iostream>
#include <string>
#include "SDL.h"
#include "Window.h"
#include "Main.h"

int main(int argc, char* argv[])
{
	Window window("Ultra Test", 1920, 1080);
	window.Init();

	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

	Main main;

	while (true)
	{
		main.Update();
		main.Draw(window);

		SDL_Event event;
		if (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				break;
			}
		}
	}

	SDL_DestroyWindow(window.GetWindow());
	SDL_Quit();

	return 0;
}