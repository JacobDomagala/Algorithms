#include <vector>
#include <algorithm>

using namespace std;

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