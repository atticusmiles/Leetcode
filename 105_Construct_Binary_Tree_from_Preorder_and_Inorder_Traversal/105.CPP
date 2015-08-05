#include "../data_type.h"
#include <vector>
using namespace std;

typedef vector<int>::iterator iiter;

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
    	 return createTree(preorder.begin(),preorder.end(),inorder.begin(),inorder.end());   
    };
    TreeNode* createTree(iiter pre_begin, iiter pre_end, iiter in_begin, iiter in_end)
    {
    	if(pre_begin==pre_end) return NULL;

    	TreeNode* this_node = new TreeNode(*pre_begin);
    	auto in_root = find(in_begin,in_end,*pre_begin);
		iiter pre_first_right = pre_begin + 1 +(in_root-in_begin);
    	this_node->left = createTree(pre_begin+1, pre_first_right, in_begin, in_root);
    	this_node->right = createTree(pre_first_right, pre_end, in_root+1, in_end);

    	return this_node;
    };
};
