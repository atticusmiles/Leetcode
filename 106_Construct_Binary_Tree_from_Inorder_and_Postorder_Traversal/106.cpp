#include "../data_type.h"
#include <vector>
using namespace std;

typedef vector<int>::iterator iiter;

class Solution {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
    	return createTree(postorder.begin(),postorder.end(),inorder.begin(),inorder.end());       
    }
    TreeNode* createTree(iiter post_begin, iiter post_end, iiter in_begin, iiter in_end)
    {
    	if(post_begin==post_end) return NULL;

    	TreeNode* this_node = new TreeNode(*(post_end-1));
    	auto in_root = find(in_begin,in_end,*(post_end-1));
		iiter post_first_right = post_begin +(in_root-in_begin);
    	this_node->left = createTree(post_begin, post_first_right, in_begin, in_root);
    	this_node->right = createTree(post_first_right, post_end-1, in_root+1, in_end);

    	return this_node;
    };
};