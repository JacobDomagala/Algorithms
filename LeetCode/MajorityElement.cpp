#include <vector>

using namespace std;

/*
	Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

	You may assume that the array is non-empty and the majority element always exist in the array.

	-----------------------------------EXAMPLE-----------------------------------

	Input: [3,2,3]
	Output: 3
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = nums[0];
        int counter = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (counter == 0) {
                counter++;
                major = nums[i];
            }
            else if (nums[i] == major) {
                counter++;
            }
            else {
                counter--;
            }
        }

        return major;
    }
};