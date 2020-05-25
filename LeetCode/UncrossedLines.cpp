#include <algorithm>
#include <vector>

using namespace std;

/*
	We write the integers of A and B (in the order they are given) on two separate horizontal lines.

	Now, we may draw connecting lines: a straight line connecting two numbers A[i] and B[j] such that:

	A[i] == B[j];
	The line we draw does not intersect any other connecting (non-horizontal) line.
	Note that a connecting lines cannot intersect even at the endpoints: each number can only belong to one connecting line.

	Return the maximum number of connecting lines we can draw in this way.

	-----------------------------------EXAMPLE-----------------------------------

	Input: A = [1,4,2], B = [1,2,4]
	Output: 2

	Explanation: We can draw 2 uncrossed lines as in the diagram.
	We cannot draw 3 uncrossed lines, because the line from A[1]=4 to B[2]=4 will intersect the line from A[2]=2 to B[1]=2.
*/

class Solution {
public:
	int maxUncrossedLines(vector<int>& a, vector<int>& b) {
		const auto m = a.size();
		const auto n = b.size();

		vector<vector<int>> dpMap(m + 1, vector<int>(n + 1));

		for (int i = 1; i <= m; ++i) {
			for (int j = 1; j <= n; ++j) {
				if (a[i - 1] == b[j - 1]) {
					dpMap[i][j] = 1 + dpMap[i - 1][j - 1];
				}
				else {
					dpMap[i][j] = max(dpMap[i - 1][j], dpMap[i][j - 1]);
				}
			}
		}

		return dpMap[m][n];
	}
};