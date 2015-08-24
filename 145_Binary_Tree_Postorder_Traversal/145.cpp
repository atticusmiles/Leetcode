#include "../data_type.h"
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) 
    {
        if(NULL==root) return vector<int>();
    	stack<pair<int,TreeNode*>> nodes;
    	nodes.push({0,root});
    	vector<int> result;

    	while(0!=nodes.size())
    	{
    		TreeNode* this_node = nodes.top().second;
    		int &visited = nodes.top().first;
    		if(!visited)
    		{
    			if(NULL!=this_node->right) nodes.push({0,this_node->right});
    			if(NULL!=this_node->left) nodes.push({0,this_node->left});
    			visited = 1;
    		}
    		else
    		{
    			result.push_back(this_node->val);
    			nodes.pop();
    		}
    	}
    	return result;
    }
};