#include <vector>
#include <algorithm>

using namespace std;

/*
	Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k),
	where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.

	-----------------------------------EXAMPLE-----------------------------------

	Input:
	[[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]

	Output:
	[[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
*/

class Solution {
	void insertToFirstPossibleIdx(vector<vector<int>>& insertTo, const vector<int>& valueToInsert, int startIdx = 0) {
		const auto size = insertTo.size();
		for (int i = startIdx; i < size; ++i) {
			if (insertTo[i][0] == -1) {
				insertTo[i] = valueToInsert;
				return;
			}
		}
	}

public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {

		const auto size = people.size();
		vector<vector<int>> result(size, vector<int>(2, -1));

		sort(people.begin(), people.end(), [](const auto& person1, const auto& person2) {
			return person1[0] < person2[0];
			});

		for (const auto& person : people) {
			const auto requestedIdx = person[1];
			if (requestedIdx == 0) {
				insertToFirstPossibleIdx(result, person);
			}
			else {
				int biggerNumsCnt = 0;
				int idx = 0;

				while (biggerNumsCnt < requestedIdx) {
					biggerNumsCnt = result[idx][0] == -1 || result[idx][0] >= person[0] ? biggerNumsCnt + 1 : biggerNumsCnt;
					++idx;
				}

				if (result[idx][0] == -1) {
					result[idx] = person;
				}
				else {
					insertToFirstPossibleIdx(result, person, idx + 1);
				}
			}

		}

		return result;
	}
};