#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/*
	Given two strings text1 and text2, return the length of their longest common subsequence.
	A subsequence of a string is a new string generated from the original string with some characters(can be none) deleted without changing the relative order of the remaining characters.
	(eg, "ace" is a subsequence of "abcde" while "aec" is not). A common subsequence of two strings is a subsequence that is common to both strings.

	If there is no common subsequence, return 0.

	-----------------------------------EXAMPLE-----------------------------------

	Input: s1 = "ab" s2 = "eidbaooo"
	Output: True
	Explanation: s2 contains one permutation of s1 ("ba").

*/

class Solution {
	
public:
	int longestCommonSubsequence(string& a, string& b) {
		
		const auto m = a.length();
		const auto n = b.length();

		vector<vector<int>> dpMap(m+1, vector<int>(n+1));

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (a[i - 1] == b[j - 1]) {
					dpMap[i][j] = 1 + dpMap[i - 1][j - 1];
				}
				else {
					dpMap[i][j] = max(dpMap[i - 1][j], dpMap[i][j - 1]);
				}
			}
		}

		return dpMap[m][n];
	}
};