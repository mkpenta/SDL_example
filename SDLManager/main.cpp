#include "SDLManager.h"
#include <iostream>

#include <SDL2/SDL.h>

int main()
{
    SDLManager* sdl;
    sdl = new SDLManager("Hello", 0, 0, 500, 500);
    
    SDL_Texture* img = sdl->loadTexture("test.bmp");
   
  
        
        
    for(int i = 0; i < 5000; i++)
    {
          sdl->setColor(0, 0 , 0, 255);
        sdl->clear();
        
        //sdl->drawImage(i ,i, 50, 50, img);
         sdl->setColor(0,255 , 0, 255);
        sdl->drawRect(100+i/3, 100, 50, 50);
    
        sdl->refresh();
      
    }
    sdl->close();
}