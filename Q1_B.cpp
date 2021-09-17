#include<iostream>
/*This is the code for Question 1, Part B
 * Author: Jonny Chen
 * Last Date Motified: 9/10/2021
 * */
int main()
{
	std::cout<<"Circle Perimeter & Area Calculator\n";
	std::cout<<"Please input the radius of the circle: ";
	float radius;
	std::cin>> radius;
	float perim = 2*3.14*radius;
	float area = 3.14*radius*radius;
	std::cout<<"The perimeter of the circle is " << perim << "\n";
	std::cout<<"The area of the circle is " << area << "\n";
}

