#include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

/*
	Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

	-----------------------------------EXAMPLE-----------------------------------

	Input: [0,1]
	Output: 2
	Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
*/

class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		const auto size = nums.size();
		unordered_map<int, int> occur;
		occur[0] = 0;
		int pref = 0;
		int res = 0;
		for (int i = 0; i < size; ++i) {
			pref += nums[i] == 0 ? -1 : 1;

			if (occur.find(pref) != occur.end()) {
				res = max(res, 1 + i - occur[pref]);
			}
			else {
				occur[pref] = i + 1;
			}
		}
		return res;
	}
};