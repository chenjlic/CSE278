#include<iostream>
/*This is the code for Question 3
 * Author: Jonny Chen
 * Last Date Motified: 09/13/21
 **/

int main() {

	std::cout<<"How many numbers do you want in the array?(20 Max): ";
	int size;
	std::cin>>size;
	int num;
	int nums [size];
	for(int n = 0; n < size; n++) {
		std::cout<<"Enter a number you want in the array: ";
		std::cin>>num;
		nums[n] = num;
	}
	std::cout<<"There are " << size << " numbers\n";
	std::cout<<"The numbers are: [";
	for(int i = 0; i < size; i++) {
		if(i+1 != size) {
			std::cout<< nums[i] << ", ";
		} else {
			std::cout<< nums[i] <<"]\n";
		}
	}
	int large = nums[0];
	int small = nums[0];
	int median;
	for(int j = 0; j < size; j++) {
		if(nums[j] > large) {
			large = nums[j];
		}
		if(nums[j] < small) {
			small = nums[j];
		}
		if(size%2 == 0) {
			median = (nums[size/2]);
		} else {
			median = (nums[(size-1)/2]+nums[(size+1)/2])/2;
		}
	}
	std::cout<<"The maximum number is: " << large << "\n";
	std::cout<<"The minimum number is: " << small << "\n";
	std::cout<<"The median number is: " << median << "\n";

}
