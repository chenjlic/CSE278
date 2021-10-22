#include"Rectangle.h"
#include<iostream>

//constructor::


Rectangle::Rectangle(int H, int W)
{
	this->Height=H;
	this->width=W;
}

Rectangle::~Rectangle()
{

}

int Rectangle::getPerimeter()
{
	return((Height*2)+(width*2));
}

int Rectangle::getSize()
{
	return(Height*width);
}
