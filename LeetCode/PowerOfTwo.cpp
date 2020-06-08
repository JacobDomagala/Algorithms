/*
	Given an integer, write a function to determine if it is a power of two.

	-----------------------------------EXAMPLE-----------------------------------

	Input: 1
	Output: true
	Explanation: 2^0 = 1
*/

class Solution {
public:
	bool isPowerOfTwo(int n) {
		if (n <= 0) {
			return false;
		}

		return !(n & (n - 1));
	}
};