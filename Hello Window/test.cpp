//written in C++ following http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index2.php


#include <SDL2/SDL.h>
#include<string>
#include<iostream>

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Screen inital location
const int SCREEN_XLOC = 0;
const int SCREEN_YLOC = 0;

SDL_Window* init(std::string);
void closeSDL(SDL_Window*);

int main( int argc, char* args[] )
{
	//Create window and drawing surface pointers
	SDL_Window* window = NULL;
	SDL_Surface* screenSurface = NULL;
	
	//try to initialize the window
	window = init("Hello World");
	
	if(window != NULL)
	{
	    //get the drawing surface from the window
        screenSurface = SDL_GetWindowSurface( window );
       
       //----DRAW THINGS ON THE SURFACE
		 //Fill the surface white
    	SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );



		//----AFTER DRAWING UPDATE TEH SURFACE
		SDL_UpdateWindowSurface( window );
	
        //Wait 
    	SDL_Delay( 10000 );

       closeSDL(window);
	}
	else
	{
	    std::cout<<"window initialization failed "<< SDL_GetError() <<std::endl;
	}
	
	return 0;

}

/*
Close out SDL and cleanup
*/
void closeSDL(SDL_Window* window)
{
	SDL_DestroyWindow( window );
    SDL_Quit();
}

/*
given a title bar string, this function attempts to intialize SDL
and create a window witht the the given title
It returns a window, or NULL is none is created
*/
SDL_Window* init(std::string title)
{
  	//Initialize SDL
	SDL_Init( SDL_INIT_VIDEO );
	
	//Create window and return a pointer to the window
    SDL_Window* window = SDL_CreateWindow( title.c_str(), SCREEN_XLOC, SCREEN_YLOC, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );

    return window;
}
