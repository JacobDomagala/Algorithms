#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <set>
#include <algorithm>
#include <deque>
#include <array>

using namespace std;

/*
	Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

	Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

	The order of output does not matter.

	-----------------------------------EXAMPLE-----------------------------------
	Input:
	s: "cbaebabacd" p: "abc"

	Output:
	[0, 6]

	Explanation:
	The substring with start index = 0 is "cba", which is an anagram of "abc".
	The substring with start index = 6 is "bac", which is an anagram of "abc".
*/

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {

		const auto sLen = s.length();
		const auto len = p.length();

		vector<int> result;

		unordered_map<char, int> elMap;
		for (const char c : p) {
			elMap[c]++;
		}

		int counter = len;
		int leftIndex = 0;

		for (int i = 0; i < sLen; ++i) {
			if (elMap[s[i]]-- >= 1) {
				counter--;
			}

			if (counter == 0) {
				result.push_back(leftIndex);
			}

			if (i - leftIndex == len - 1 && elMap[s[leftIndex++]]++ >= 0) {
				counter++;
			}
		}

		return result;
	}
};