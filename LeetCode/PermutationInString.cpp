#include <list>
#include <map>

using namespace std;

/*
	Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
	In other words, one of the first string's permutations is the substring of the second string.

	-----------------------------------EXAMPLE-----------------------------------

	Input: s1 = "ab" s2 = "eidbaooo"
	Output: True
	Explanation: s2 contains one permutation of s1 ("ba").

*/

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		const auto s1Len = s1.length();
		const auto s2Len = s2.length();

		if (s1Len > s2Len) {
			return false;
		}

		unordered_map<char, int> occurMap;
		for (const char ch : s1) {
			occurMap[ch]++;
		}

		int right = 0;
		int left = 0;
		int counter = s1Len;

		while (right < s2Len) {
			if (occurMap[s2[right++]]-- > 0) {
				counter--;
			}

			if (counter == 0) {
				return true;
			}

			if ((right - left == s1Len) && occurMap[s2[left++]]++ >= 0) {
				counter++;
			}
		}

		return false;
	}
};