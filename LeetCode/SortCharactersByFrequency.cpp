#include <string>
#include <algorithm>
#include <vector>

using namespace std;

/*
	Given a string, sort it in decreasing order based on the frequency of characters.

	-----------------------------------EXAMPLE-----------------------------------

	Input:
	"tree"

	Output:
	"eert"

	Explanation:
	'e' appears twice while 'r' and 't' both appear once.
	So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
*/

class Solution {
public:
	string frequencySort(string s) {
		string returnStr;
		unordered_map<char, int> charsFreq;

		for (char c : s) {
			charsFreq[c]++;
		}

		vector<pair<char, int>> freqVec(charsFreq.begin(), charsFreq.end());

		sort(freqVec.begin(), freqVec.end(), [](const auto& pair1, const auto& pair2) {
			return pair1.second > pair2.second;
			});

		for_each(freqVec.begin(), freqVec.end(), [&returnStr](const auto& pair) {
			for (int i = 0; i < pair.second; ++i) {
				returnStr += pair.first;
			}
			});

		return returnStr;
	}
};