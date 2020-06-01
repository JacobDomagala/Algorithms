#include <vector>

using namespace std;

/*
	Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

	-----------------------------------EXAMPLE-----------------------------------

	Input: [-2,1,-3,4,-1,2,1,-5,4],
	Output: 6

	Explanation: [4,-1,2,1] has the largest sum = 6.
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int pref = 0;
		int res = INT_MIN;
		for (auto val : nums) {
			pref += val;
			res = max(res, pref);
			pref = max(0, pref);
		}

		return res;
	}
};