#include<iostream>
#include<string>
#include<boost/algorithm/string.hpp>
/*This is the code for Question 2, Part B
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
		boost::to_lower(acc);
		if(acc == "21_cse_c++_fall" &&
			pass=="278A&B") {
			correct = true;
			std::cout<<"Login Success!\n";
		} else {
			std::cout<<"Login Failed.\n";
		}	
	}
}
