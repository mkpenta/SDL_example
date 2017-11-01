//written in C++ following http://lazyfoo.net/tutorials/SDL/01_hello_SDL/index2.php
//https://wiki.libsdl.org/SDL_Event

#include <SDL2/SDL.h>
#include<string> //c++ strings
#include<iostream> //cout, cin, endl
#include <stdlib.h> //exit

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

//Screen inital location
const int SCREEN_XLOC = 0;
const int SCREEN_YLOC = 0;

SDL_Window* WINDOW = NULL;

void initSDL(std::string);
void closeSDL();

void processEvents();
void keyPressed(SDL_Event);
void keyReleased(SDL_Event);

int main( int argc, char* args[] )
{
	//try to initialize the WINDOW - quits on failure
	initSDL("Hello World");

	//While application is running
	while( WINDOW != NULL)
	{
		//check for events and process them
		processEvents();
	}

	return 0;
}

/*
Process all events in the queue
Call the appropriate event handling function
*/
void processEvents()
{
	SDL_Event e;
	//While there are still events in the queue remove one and handle it
	while( SDL_PollEvent( &e ) != 0 )
	{
		switch(e.type)
		{
			case SDL_QUIT:
				std::cout<<"QUIT EVENT "<<e.type<<std::endl;
				closeSDL();
				break;
			case SDL_KEYDOWN:
				std::cout<<"KEY DOWN EVENT "<<e.type<<std::endl;
				keyPressed(e);
				break;
			case SDL_KEYUP:
				std::cout<<"KEY UP EVENT "<<e.type<<std::endl;
				keyReleased(e);
				break;
			default:
				std::cout<<"Unhandled Event: "<<e.type<<std::endl;
				break;
		}
		
	}
}

/*
Close out SDL and cleanup
*/
void closeSDL()
{
	SDL_DestroyWindow( WINDOW );
    SDL_Quit();
    WINDOW = NULL;
}

/*
attempt to intialize SDL and create a WINDOW with the the given title
global WINDOW is NULL if intit fails or no WINDOW is created
*/
void initSDL(std::string title)
{
	WINDOW = NULL;
  	//Initialize SDL
	SDL_Init( SDL_INIT_VIDEO );
	
	//Create WINDOW and set the global WINDOW pointer
    WINDOW = SDL_CreateWindow( title.c_str(), SCREEN_XLOC, SCREEN_YLOC, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
   
    //check for a failure
    if(WINDOW == NULL)
    {
    	std::cout<<"Quitting - Initialization Failure SDL ERROR "<<SDL_GetError()<<std::endl;
    	exit(0);
    }
}

void keyPressed(SDL_Event e)
{
	//https://wiki.libsdl.org/SDL_Keycode
		std::cout<<"press"<<std::endl;
		switch(e.key.keysym.sym )
		{
			case SDLK_UP:
				std::cout<<"UP"<<std::endl;
				break;
			case SDLK_a:
				std::cout<<"A"<<std::endl;
				break;
			default:
				std::cout<<SDL_GetKeyName(e.key.keysym.sym)<<std::endl;
				break;	
		}
}

void keyReleased(SDL_Event e)
{
		std::cout<<"release"<<std::endl;
    
}