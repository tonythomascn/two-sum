/*
Add Binary

24% Accepted
Given two binary strings, return their sum (also a binary string).

Have you met this question in a real interview? Yes
Example
a = 11

b = 1

Return 100
*/
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