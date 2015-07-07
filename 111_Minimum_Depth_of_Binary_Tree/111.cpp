#include <stdlib.h>
//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	int minDepth(TreeNode* root) 
	{
		if (NULL==root) return 0;
		else
		{
			int left_dep = minDepth(root->left);
			int right_dep = minDepth(root->right);
			return (left_dep>right_dep)? (right_dep+1):(left_dep+1);
		}
	}
};