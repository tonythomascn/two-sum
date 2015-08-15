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
	int binarya = std::stoi(a, 0, 2);
	int binaryb = std::stoi(b, 0, 2);
	if (!(binarya + binaryb)) return "0";
	//access two binary integers and transform it into a string usn g bitset
	//16 is the size of the bitset size
	string s = std::bitset<16>(binarya + binaryb).to_string();
	return s.substr(s.find("1"));
}

string addBinary2(string&a, string&b) {
	int carry = 0;
	string result = "";
	int ai, bj, val;
	//iterate every digit in both string from the back to the front;
	//and add carry with them
	for (int i = a.size() - 1, j = b.size() - 1; i >= 0 || j >= 0; i--, j--) {
		ai = i >= 0 ? a[i] - '0' : 0;
		bj = j >= 0 ? b[j] - '0' : 0;
		val = (ai + bj + carry) % 2;
		carry = (ai + bj + carry) / 2;
		result.insert(result.begin(), val + '0');
	}
	//add the carry if exist
	if (carry)
		result.insert(result.begin(), '1');
	return result;
}
//int main()
//{
//	string a = "0";
//	string b = "0";
//	std::cout << addBinary(a, b) << std::endl;
//	system("pause");
//	return 0;
//}
