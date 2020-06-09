#include <string>

using namespace std;

/*
	Given a string s and a string t, check if s is subsequence of t.

    A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) 
    of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).

	-----------------------------------EXAMPLE-----------------------------------

	Input: s = "abc", t = "ahbgdc"
    Output: true
*/

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }

        int idx = 0;
        const auto size = s.length();

        for (auto ch : t) {
            if (ch == s[idx]) {
                if (idx == size - 1) {
                    return true;
                }
                idx++;
            }
        }

        return false;
    }
};