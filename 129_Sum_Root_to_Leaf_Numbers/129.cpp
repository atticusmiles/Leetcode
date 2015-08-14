#include "../data_type.h"
using namespace std;

class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {
    	if(NULL==root) return 0;
    	int sum = 0;
    	addPathSum(root,0,sum);
    	return sum;
    }
private:
    void addPathSum(TreeNode* root, int path_sum , int& sum)
    {
    	if(NULL==root->left && NULL==root->right)
    	{
    		sum+=(path_sum*10+root->val);
    		return;
    	}

		if(NULL!=root->left)
    	{
    		addPathSum(root->left, path_sum*10+root->val, sum);
    	}
    	if(NULL!=root->right)
    	{
    		addPathSum(root->right, path_sum*10+root->val, sum);
    	}
    	return;
    }
};