/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include "../data_type.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
    	if(NULL==root) return NULL;

    	TreeNode* tmp=root->left;
    	root->left = invertTree(root->right);
    	root->right = invertTree(tmp);

    	return root;
    }
};