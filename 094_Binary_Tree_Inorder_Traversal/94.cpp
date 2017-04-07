#include <stack>
#include "../data_type.h"
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) 
    {
    	if(NULL==root) return vector<int>();
    	vector<int> traversal;
        stack<pair<TreeNode*,bool>> output;
        output.push({root,false});
        while(!output.empty())
        {
        	auto this_node = &(output.top());

        	if(NULL!=this_node->first->left && false == this_node->second )
        	{
    			this_node->second = true;
    			output.push({this_node->first->left,false});
    			continue;
        	}
        	else
        	{
        		this_node->second = true;
	        	traversal.push_back(this_node->first->val);
	        	output.pop();
	        	if(NULL!=this_node->first->right) output.push({this_node->first->right,false});
        	}
        }
        return traversal;
    }
};