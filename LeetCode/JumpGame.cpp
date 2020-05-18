#include <vector>
#include <algorithm>

using namespace std;

/*
    Given an array of non-negative integers, you are initially positioned at the first index of the array.

    Each element in the array represents your maximum jump length at that position.

    Determine if you are able to reach the last index.

    -----------------------------------EXAMPLE-----------------------------------

    Input: nums = [2,3,1,1,4]
    Output: true
    Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int biggestJump = 0;
        for (int i = 0; i < n; i++) {
            if (biggestJump < i) return false;
            biggestJump = max(i + nums[i], biggestJump);
        }

        return true;
    }
};