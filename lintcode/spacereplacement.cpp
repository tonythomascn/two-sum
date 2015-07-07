/*
Space Replacement

16% Accepted
Write a method to replace all spaces in a string with %20. The string is given in a characters array, you can assume it has enough space for replacement and you are given the true length of the string.

Have you met this question in a real interview? Yes
Example
Given "Mr John Smith", length = 13.

The string after replacement should be "Mr%20John%20Smith".

Note
If you are using Java or Python，please use characters array instead of string.

Challenge
Do it in-place.
*/
#include "stdafx.h"
/**
* @param string: An array of Char
* @param length: The true length of the string
* @return: The true length of new string
*/
int replaceBlank(char string[], int length) {
	int space = 0;
	for (int i = 0; i < length; i++) {
		if (' ' == string[i]) space++;
	}
	for (int i = length + 2 * space - 1, j = length - 1; j >= 0; j--) {
		if (' ' == string[j]) {
			string[i--] = '0';
			string[i--] = '2';
			string[i--] = '%';
		}
		else {
			string[i--] = string[j];
		}
	}
	return length + 2 * space;
}
//int main() {
//	char string[13] = "Hello World";
//	replaceBlank(string, 11);
//}