/*
needs to handle destroying all textures at close
maintain a list of all textures that have been loaded
*/


#include "SDLManager.h"

SDLManager::SDLManager(std::string title, int x, int y, int w, int h)
{
    window = nullptr;
    renderer = nullptr;
    // Initialize SDL
	SDL_Init(SDL_INIT_VIDEO);
    // create the window and renderer
    window = SDL_CreateWindow(title.c_str(), x, y, w, h, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}
        

SDL_Window* SDLManager::getWindow()
{
    return window;
}
        
void SDLManager::drawRect(int x, int y, int w, int h)
{
    SDL_Rect r;
	
	r.x = x;
    r.y = y;
	r.w = w;
	r.h = h;
	
	SDL_RenderFillRect( renderer, &r );
}
        
void SDLManager::drawImage(int x, int y, int w, int h, SDL_Texture* texture)
{
	SDL_Rect texr; 
	texr.x = x; 
	texr.y = y; 
	texr.w = w; 
	texr.h = h; 
	SDL_RenderCopy(renderer, texture, NULL, &texr);
}
        
void SDLManager::drawText(int x, int y, std::string )
{
	
	//maybe here -- https://stackoverflow.com/questions/22886500/how-to-render-text-in-sdl2
    
}
void SDLManager::setColor(int r, int g, int b, int a)
{
	SDL_SetRenderDrawColor( renderer, r, g, b, a);
}

void SDLManager::close()
{
	SDL_DestroyWindow( window );
    SDL_Quit();
}

void SDLManager::clear()
{
	SDL_RenderClear(renderer);
}

void SDLManager::refresh()
{
	SDL_RenderPresent(renderer);
}
 
SDL_Texture* SDLManager::loadTexture(std::string src)
{
    SDL_Texture* img;
    SDL_Surface* surf;
    
    // modified from lazy foo
	surf = SDL_LoadBMP(src.c_str());
	
	if( surf == NULL )
	{
		printf( "Unable to load image %s! ", src.c_str() );
	}
	else
	{
    	img = SDL_CreateTextureFromSurface( renderer,surf);
		if( img == NULL )
		{
			printf( "Unable to create texture from %s! SDL Error: %s\n", src.c_str(), SDL_GetError() );
		}

		//Get rid of old loaded surface
		SDL_FreeSurface( surf );
	}

	return img;
}
