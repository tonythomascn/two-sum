/*
Compare Strings

27% Accepted
Compare two strings A and B, determine whether A contains all of the characters in B.

The characters in string A and B are all Upper Case letters.

Have you met this question in a real interview? Yes
Example
For A = "ABCD", B = "ACD", return true.

For A = "ABCD", B = "AABC", return false.

Note
The characters of B in A are not necessary continuous or ordered.
*/
#include "stdafx.h"
/**
* @param A: A string includes Upper Case letters
* @param B: A string includes Upper Case letter
* @return:  if string A contains all of the characters in B return true
*           else return false
*/
#include <string>
using std::string;
bool compareStrings(string A, string B) {
	if (B.length() > A.length())
		return false;

	int a[26] = { 0 };
	for (char c : A) {
		a[c - 'A']++;
	}
	for (char c : B) {
		a[c - 'A']--;
		if (0 > a[c - 'A'])
			return false;
	}
	return true;
}

//int main() {
//	
//	compareStrings("ABCD", "ACD");
//	compareStrings("ABCD", "AABC");
//}