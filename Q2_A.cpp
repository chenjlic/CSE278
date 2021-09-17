#include<iostream>
/*This is the code for Queston 2, Part A
 * Author: Jonny Chen
 * Last Date Motified: 9/10/2021
 * */
int main()
{
	bool correct = false;
	while(!correct) {
		std::string acc, pass;
		std::cout<<"Account: ";
		std::cin>> acc;
		std::cout<<"Password: ";
		std::cin>> pass;
		if(acc=="21_CSE_c++_Fall" && pass=="278A&B") {
			std::cout<<"Login Success!\n";
			correct = true;
		} else {
			std::cout<<"Login Failed.\n";
		}
	}	
}
