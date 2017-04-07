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
	int maxDepth(TreeNode* root) 
    {
        if (NULL==root) return 0;
        else
        {
        	int left_dep = maxDepth(root->left);
        	int right_dep = maxDepth(root->right);
        	return (left_dep<right_dep)? (right_dep+1):(left_dep+1);
        }
    }

    bool isBalanced(TreeNode* root) 
    {
        if(NULL==root) return true;
        return isBalanced(root->left) && isBalanced(root->right) && (abs(maxDepth(root->left)-maxDepth(root->right))<=1);
    }
};