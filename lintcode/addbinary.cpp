#include "stdafx.h"
#include <string>
#include <iostream>
#include <bitset>
using std::string;
string addBinary(string& a, string& b) {
	// Write your code here
	int binarya = std::stoi(a, 0, 2);
	int binaryb = std::stoi(b, 0, 2);
	if (!(binarya + binaryb)) return "0";
	string s = std::bitset<8>(binarya + binaryb).to_string();
	return s.substr(s.find("1"));
}

//int main()
//{
//	string a = "0";
//	string b = "0";
//	std::cout << addBinary(a, b) << std::endl;
//	system("pause");
//	return 0;
//}