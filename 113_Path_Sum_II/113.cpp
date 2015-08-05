#include "../data_type.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
    	if(NULL==root) return vector<vector<int>>();
    	
    	vector<int> path;
    	vector<vector<int>> result;
    	findPath(root, sum, path, result);
    	return result;
    }
    void findPath(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &result)
    {
    	path.push_back(root->val);
    	if(NULL==root->left && NULL==root->right)
    	{
    		if(sum==root->val) 
    		{
    			result.push_back(path);
    		}
    	}
    	else
    	{
    		if(NULL!=root->left)
    		{
    			findPath(root->left, sum-root->val, path, result);
    		}
    		if(NULL!=root->right)
    		{
    			findPath(root->right, sum-root->val, path, result);
    		}
    	}
    	path.pop_back();
    }
};