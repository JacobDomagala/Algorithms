#include <vector>

using namespace std;

/*
	Return the root node of a binary search tree that matches the given preorder traversal.

	(Recall that a binary search tree is a binary tree where for every node, any descendant of node.left has a value < node.val, and any descendant of node.right has a value > node.val.
	Also recall that a preorder traversal displays the value of the node first, then traverses node.left, then traverses node.right.)

	It's guaranteed that for the given test cases there is always possible to find a binary search tree with the given requirements.

	-----------------------------------EXAMPLE-----------------------------------

	Input: [8,5,1,7,10,12]
	Output: [8,5,10,1,7,null,12]
*/


//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
	TreeNode* m_root = nullptr;

	void AddNode(int value) {
		auto currNode = m_root;

		while (1) {
			const auto currVal = currNode->val;
			if (value > currVal) {
				if (!currNode->right) {
					currNode->right = new TreeNode(value);
					break;
				}
				currNode = currNode->right;
			}
			else {
				if (!currNode->left) {
					currNode->left = new TreeNode(value);
					break;
				}

				currNode = currNode->left;
			}
		}
	}

public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		m_root = new TreeNode(preorder[0]);
		for (int i = 1; i < preorder.size(); ++i) {
			AddNode(preorder[i]);
		}

		return m_root;
	}
};