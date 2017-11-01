
#include "rect.h"


void rect::setAll(int x0, int y0, int w, int h, int r0, int g0, int b0)
{
    x = x0;
    y = y0;
    height = h;
    width= w;
    r = r0;
    b = b0;
    g = g0;
}

int rect::getX()
{
    return x;
}

int rect::getY()
{
    return y;
}
int rect::getW()
{
   return width; 
}
int rect::getH()
{
    return height;
}
int rect::getR()
{
    return r;
}
int rect::getG()
{
    return g;
}
int rect::getB()
{
    return b;
}
void rect::update()
{
    x = x + 5;
}

