#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
//#define argv
/*This is the code for CSE278, Lab 4
* Author: Jonny Chen
* UniqueID: chenjl
* Last Date Motified: 9/24/2021
* */
void Q1() {
     std::cout<<"This is the code for the first question";
}
 
void Q2() {
     std::ifstream inFile("input.txt");
     if(!inFile.good()) {
             std::cerr<<"Unable to read input.txt\n";
     }
     int res = 0, num, count;
     while(inFile >> num) {
             res+= num;
             count++;
     }
     res = res/count;
     std::cout<<res;
}
 
void Q3() {
     using StrIntMap = std::unordered_map<std::string, int>;
     std::ifstream inFile("input.txt");
     std::ifstream namFile("NameFile.txt");
     if(!inFile.good()) {
             std::cerr<<"Unable to read input.txt\n";
     }else if(!namFile.good()){
             std::cerr<<"Unable to read NameFile.txt\n";
     }
     std::string s,word;
     int i = 0, check= 0;
     StrIntMap res = {};
     while((inFile >> i) && getline(namFile,s)) {
             res.insert(std::pair<std::string,int> {s,i});
     }
     std::cin>>word;
     if(res.find(word) == res.end()) {
	     std::cout<<"Not exists";
     	     return;
     } else {
	     std::cout<<res.at(word);
     }
     std::cout<<res[s];
}
 
int main(int argc, char *argv[]) {
 
     if(argc<2) {
             std::cout<<"Not enough arguments\n";
     }
 
     switch(argv[1][1]){
             case '1':Q1();break;
             case '2':Q2();break;
             case '3':Q3();break;
     }
}
