#include "../data_type.h"
#include <stack>
using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) 
    {
    	if(!root) return;
    	stack<TreeNode*> nodes;
    	TreeNode* header = new TreeNode(0);
    	TreeNode* tail = header;
    	nodes.push(root);
    	preoder_tvs(nodes, tail);
    }
    void preoder_tvs(stack<TreeNode*> &cache, TreeNode* &tail)
    {
    	if(cache.size()==0) return;
    	else
    	{
    		TreeNode* this_node = cache.top();
    		tail->right = this_node;
    		tail = this_node;
    		cache.pop();

    		if(NULL!= this_node->right) cache.push(this_node->right);
    		if(NULL!= this_node->left) cache.push(this_node->left);
    		
    		this_node->left = NULL;
    		this_node->right = NULL;
    	}
    	preoder_tvs(cache,tail);
    }
};