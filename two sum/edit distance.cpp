
/**
Given two words word1 and word2, find the minimum number of steps required to convert word1 to word2.
(each operation is counted as 1 step.)

You have the following 3 operations permitted on a word:

a) Insert a character
b) Delete a character
c) Replace a character
*/
#include <algorithm>
#include <string>
#include <vector>
using std::vector;
using std::string;

int minDistance(string word1, string word2) {
	if ("" == word1)
		return word2.length();
	if ("" == word2)
		return word1.length();

	int m = word1.length();
	int n = word2.length();
	std::vector<std::vector<int>> v(m + 1, std::vector<int>(n + 1, 0));
	for (int i = 0; i <= m; i++){
		for (int j = 0; j <= n; j++){		
			if (0 == i)
				v[i][j] = j;
			else if (0 == j)
				v[i][j] = i;
			else{
				if (word1[i - 1] == word2[j - 1])
					v[i][j] = v[i - 1][j - 1];
				else
					v[i][j] = std::min(std::min(v[i][j - 1], v[i - 1][j]), v[i - 1][j - 1]) + 1;
			}
		}
	}
	return v[m][n];
}

//int main()
//{
//	
//	printf(" %d", minDistance("ab", "a"));
//	system("pause");
//	return 0;
//}