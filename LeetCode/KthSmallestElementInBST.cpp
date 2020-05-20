#include <vector>

using namespace std;

/*
	Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.

	-----------------------------------EXAMPLE-----------------------------------

	Input: root = [3,1,4,null,2], k = 1
		3
	   / \
	  1   4
	   \
		2

	Output: 1
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
	vector<int> m_values;

	void traverseSubTree(TreeNode* node) {
		if (!node) {
			return;
		}

		traverseSubTree(node->right);
		m_values.push_back(node->val);
		traverseSubTree(node->left);
	}

public:
	int kthSmallest(TreeNode* root, int k) {
		m_values.push_back(root->val);

		// Traverse left side of tree
		traverseSubTree(root->left);

		if (m_values.size() >= k) {
			return m_values[m_values.size() - k];
		}

		int numOfNodesSoFar = m_values.size();
		k = k - numOfNodesSoFar;

		// Traverse right side of tree
		traverseSubTree(root->right);

		return m_values[m_values.size() - k];
	}
};