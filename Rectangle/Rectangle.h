#include<iostream>

class Rectangle{

    public:
        Rectangle(int H, int W);
        ~Rectangle();
        int getPerimeter();
        int getSize();
    private:
        int Height;
        int width;
           
};
