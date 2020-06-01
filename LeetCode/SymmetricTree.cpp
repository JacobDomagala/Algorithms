#include <vector>

using namespace std;

/*
	Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

	-----------------------------------EXAMPLE-----------------------------------

	For example, this binary tree [1,2,2,3,4,4,3] is symmetric:

		1
	   / \
	  2   2
	 / \ / \
	3  4 4  3
*/

// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) {
			return true;
		}

		queue<TreeNode*> q;
		q.push(root->left);
		q.push(root->right);

		while (!q.empty()) {
			auto left = q.front();
			q.pop();

			auto right = q.front();
			q.pop();

			if (!left && right || !right && left)
				return false;
			if (left && right) {
				if (left->val != right->val) {
					return false;
				}

				q.push(left->left);
				q.push(right->right);

				q.push(left->right);
				q.push(right->left);
			}
		}

		return true;
	}
};