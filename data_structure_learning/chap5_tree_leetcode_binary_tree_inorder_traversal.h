/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
*/

using std::vector;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> nums;
		inorderrecursion(root, nums);
		return nums;
	}

private:
	void inorderrecursion(TreeNode* node, vector<int>& nums) {
		if (node != NULL) {
			inorderrecursion(node->left, nums);
			nums.push_back(node->val);
			inorderrecursion(node->right, nums);
		}
	}
};