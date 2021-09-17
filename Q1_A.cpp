#include<iostream>
/* This is the code for Question 1, Part A
 * Author: Jonny Chen
 * Last Motified Date: 9/10/2021
 * */
int main() 
{
	std::cout<<"Area Calculator\n";
	std::cout<<"Please input the width of the rectangle: ";
	int width;
	std::cin>> width;
	std::cout<<"Please input the height of the rectangle: ";
	int height;
	std::cin>> height;
	int area = width*height;
	std::cout<<"The area of the rectangle is: " << area << "\n";
	
}
