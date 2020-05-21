#include <vector>

using namespace std;

/*
	Given a non negative integer number num. For every numbers i in the range 0 <= i <= num calculate the number of 1's in their binary representation and return them as an array.

	-----------------------------------EXAMPLE-----------------------------------

	Input: 2
    Output: [0,1,1]

*/

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> result = { 0 };
        for (int i = 1; i <= num; ++i) {
            if (i % 2 == 0) {
                result.push_back(result[i / 2]);
            }
            else {
                result.push_back(result[i - 1] + 1);
            }
        }

        return result;

    }
};