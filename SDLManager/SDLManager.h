//Good explanation of all the parts - https://stackoverflow.com/questions/21007329/what-is-a-sdl-renderer
//the above post author has a blog about C++ and SDL2 - http://headerphile.com/ 

//Textures are apparently the way to go for doing most drawing


#ifndef SDLMANAGER_H
#define SDLMANAGER_H

#include <SDL2/SDL.h>
#include<string>

class SDLManager
{
    private:
        SDL_Window* window;
        SDL_Renderer *renderer;

    
    public:
        SDLManager(std::string title, int x, int y, int w, int h);
        
        SDL_Window* getWindow();
        
        SDL_Texture* loadTexture(std::string src);
        
        
        void drawRect(int x, int y, int w, int h);
        
        void drawImage(int x, int y, int w, int h, SDL_Texture* text);
        
        void drawText(int x, int y, std::string);
        
        void setColor(int r, int g, int b, int a);
        
        void refresh();
        
        void close();
        
        void clear();
        
};
#endif 