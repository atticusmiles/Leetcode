#include "../data_type.h"
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) 
    {
    	if(NULL==root) return vector<int>();
    	stack<TreeNode*> nodes;
    	nodes.push(root);
    	vector<int> result;

    	while(0!=nodes.size())
    	{
    		TreeNode* this_node = nodes.top();
    		nodes.pop();
    		result.push_back(this_node->val);
    		if(NULL!=this_node->right) nodes.push(this_node->right);
    		if(NULL!=this_node->left) nodes.push(this_node->left);
    	}
    	return result;
    }
};