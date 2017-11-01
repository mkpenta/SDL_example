

#ifndef _RECT_H
#define _RECT_H

class rect
{
    private:
        int x;
        int y;
        int r;
        int g;
        int b;
        int width;
        int height;
    
    public:
        void setAll(int x, int y, int w, int h, int r, int g, int b);
        int getX();
        int getY();
        int getW();
        int getH();
        int getR();
        int getG();
        int getB();
        void update();
};
#endif 