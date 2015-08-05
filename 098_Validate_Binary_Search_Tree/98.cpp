#include "../data_type.h"

class Solution {
public:
    bool isValidBST(TreeNode* root) 
    {
    	if(NULL==root) return true;
    	return isValid(root,LLONG_MAX,LLONG_MIN);
    }
private:
    bool isValid(TreeNode* root, long long top, long long bottom)
    {
    	if(root->val>=top || root->val<=bottom) return false;
    	if((NULL!=root->left) && !isValid(root->left,root->val,bottom)) return false;
    	if((NULL!=root->right) && !isValid(root->right,top,root->val)) return false;
    	return true;
    }
};