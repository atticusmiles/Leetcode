#include "../data_type.h"

class Solution {
public:
    void connect(TreeLinkNode *root) 
    {
        if(NULL==root) return;
        link(root);
    }
    void link(TreeLinkNode* root)
    {
    	if(NULL==root->left || NULL==root->right) return;
    	TreeLinkNode* left_last = root->left;
    	TreeLinkNode* right_first = root->right;
    	while(NULL!=left_last)
    	{
    		left_last->next = right_first;
    		left_last = left_last->right;
    		right_first = right_first->left;
    	}
    	link(root->left);
    	link(root->right);
    }
};