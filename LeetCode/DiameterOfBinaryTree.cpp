#include <algorithm>

using namespace std;

/*
	Given a binary tree, you need to compute the length of the diameter of the tree.
	The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

	-----------------------------------EXAMPLE-----------------------------------

	Input:

		 4
	   /   \
	  2     7
	 / \   / \
	1   3 6   9

	Output:

	Return 4, which is the length of the path [1,2,4,7,9]

	Note: The length of path between two nodes is represented by the number of edges between them.
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
	pair<int, int> TraverseSubtree(TreeNode* root) {
		if (!root) {
			return { 0,0 };
		}

		auto left = TraverseSubtree(root->left);
		auto right = TraverseSubtree(root->right);

		int leftFirst = root->left ? 1 + left.first : 0;
		int rightFirst = root->right ? 1 + right.first : 0;

		int firstVal = max(leftFirst, rightFirst);
		int secondSum = max({ leftFirst + rightFirst, left.second, right.second });

		return make_pair(firstVal, secondSum);
	}

public:
	int diameterOfBinaryTree(TreeNode* root) {
		auto val = TraverseSubtree(root);

		return max(val.first, val.second);
	}
};