#include "Main.h"
#include "SDL.h"

Main::Main()
{
	renderer = ultralight::Renderer::Create();

	view = renderer->CreateView(1920, 1080, true);
	view->LoadHTML(R"(
	<html>
    <head>
        <link rel="stylesheet" type="text/css" href="https://necolas.github.io/normalize.css/8.0.1/normalize.css">
    </head>
    <body>
        <div class="container">
            <img class="spin-img" src="https://ukstudy.com/wp-content/uploads/logo-lincoln-uni-large-1.png">
        </div>
    </body>

    <style>
        body {
            height: 100%;
        }

        .container {
            height: 100%;
            display: flex;
            align-items: center;
        }

        .spin-img {
            margin-left: auto;
            margin-right: auto;
            animation:spin 1s linear infinite;
        }

        @keyframes spin { 100% { transform:rotate(360deg); } }
    </style>
	</html>
	)");
}

Main::~Main()
{
	renderer = nullptr;
}

void Main::Update()
{
	renderer->Update();
}

void Main::Draw(Window& window)
{
	// Clear the background to cornflower blue (best colour)
	SDL_SetRenderDrawColor(window.GetRenderer(), 100, 149, 237, 255);
	SDL_RenderClear(window.GetRenderer());

	// Ultralight requires this to render
	renderer->Render();

	// Check if something changed in the bitmap to rerender
	if (view->is_bitmap_dirty()) {

		// If a surface already exists, destroy it as we'll create a new one
		if (ultraSurfaceTex) 
			SDL_DestroyTexture(ultraSurfaceTex);

		// Ultralight renders offscreen, we have to blit the pixel data to an SDL texture to able to see it
		ultralight::RefPtr<ultralight::Bitmap> bitmap = view->bitmap();
		void* pixels = bitmap->LockPixels();

		// Create SDL surface from bitmap pixels
		SDL_Surface* ultraSurface = SDL_CreateRGBSurfaceFrom(pixels, bitmap->width(), bitmap->height(), bitmap->bpp() * 8, bitmap->bpp() * bitmap->width(), 0x000000ff, 0x0000ff00, 0x00ff0000, 0xff000000);

		// Create a texture from the surface we created
		ultraSurfaceTex = SDL_CreateTextureFromSurface(window.GetRenderer(), ultraSurface);
		SDL_SetTextureBlendMode(ultraSurfaceTex, SDL_BLENDMODE_BLEND);

		bitmap->UnlockPixels();
		SDL_FreeSurface(ultraSurface);
	}

	// Render the surface texture to the renderer if it's not null
	if (ultraSurfaceTex) 
		SDL_RenderCopy(window.GetRenderer(), ultraSurfaceTex, NULL, NULL);

	SDL_RenderPresent(window.GetRenderer());
}

void Main::HandleInputs()
{

}
