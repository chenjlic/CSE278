#include<iostream>
#include"Rectangle.h"

using namespace::std;

int main()
{
    Rectangle Window(5,9);
    cout<<"The perimeter of this window is:"<<Window.getPerimeter()<<endl;
    cout<<"The size of this window is:"<<Window.getSize()<<endl;
}
