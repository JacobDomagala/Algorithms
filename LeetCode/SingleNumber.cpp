#include <vector>

using namespace std;

/*
	Given a non-empty array of integers, every element appears twice except for one. Find that single one.

	-----------------------------------EXAMPLE-----------------------------------

	Input: [2,2,1]
	Output: 1
*/

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int value = 0;
		for (auto num : nums) {
			value ^= num;
		}

		return value;
	}
};