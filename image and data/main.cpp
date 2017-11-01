#include "rect.h"
#include <iostream>

int main()
{
    rect rect;
    
    rect.setAll(10, 20, 40, 40, 255, 0, 0);
    
    std::cout<<"RECT xy = "<<rect.getX()<<", "<<rect.getY()<<std::endl;
    
}