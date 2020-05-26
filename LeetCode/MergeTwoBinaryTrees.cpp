/*
	Given two binary trees and imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.

	You need to merge them into a new binary tree. The merge rule is that if two nodes overlap, then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of new tree.

	-----------------------------------EXAMPLE-----------------------------------

	Input:
	Tree 1                     Tree 2

		  1                         2
		 / \                       / \
		3   2                     1   3
	   /                           \   \
	  5                             4   7

	Output:
	Merged tree:

		 3
		/ \
	   4   5
	  / \   \
	 5   4   7
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
	TreeNode* mergeInternal(TreeNode* t1, TreeNode* t2) {
		if (t1 || t2) {
			int rightVal = t1 ? t1->val : 0;
			int leftVal = t2 ? t2->val : 0;

			auto root = new TreeNode(rightVal + leftVal);

			root->left = mergeInternal(t1 ? t1->left : nullptr, t2 ? t2->left : nullptr);
			root->right = mergeInternal(t1 ? t1->right : nullptr, t2 ? t2->right : nullptr);

			return root;
		}
		else {
			return nullptr;
		}
	}
public:
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		return mergeInternal(t1, t2);
	}
};