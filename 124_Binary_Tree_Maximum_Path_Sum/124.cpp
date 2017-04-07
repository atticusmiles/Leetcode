#include "../data_type.h"
using namespace std;

class Solution {
public:
    int maxPathSum(TreeNode* root) 
    {
    	if(NULL==root) return 0;
    	TreeNode* max_sum_tree;
    	maxUpPathSum(root,max_sum_tree);
    	int max_path_sum = INT_MIN;
    	findMaxPathSum(max_sum_tree,max_path_sum);
    	return max_path_sum;
    }
    int maxUpPathSum(TreeNode* root, TreeNode*& sumTree_this_node)
    {
    	if(NULL==root)
    	{
    		sumTree_this_node = NULL;
    		return 0;
    	}
    	TreeNode* this_node = new TreeNode(0);
    	sumTree_this_node = this_node;

    	int left_max = maxUpPathSum(root->left, this_node->left);
    	left_max = (left_max<0)? 0 : left_max;
    	int right_max = maxUpPathSum(root->right, this_node->right);
    	right_max= (right_max<0)? 0 : right_max;

    	int this_sum = max(left_max,right_max) + root->val;
    	this_node->val = this_sum;
    	return this_sum;
    }

    void findMaxPathSum(TreeNode* root,int &max_path_sum)
    {
    	int max_left = (root->left == NULL)? 0 : root->left->val;
    	int max_right = (root->right == NULL)? 0 : root->right->val;
    	int max_child = max(max_left,max_right);
    	int this_node = (max_child<0)? root->val : root->val-max_child;
    	int this_max_sum = this_node;
    	if(max_right>0) this_max_sum+=max_right;
    	if(max_left>0) this_max_sum+=max_left;
    	max_path_sum = (max_path_sum<this_max_sum)? this_max_sum : max_path_sum;
    	if(NULL!=root->left) findMaxPathSum(root->left,max_path_sum);
    	if(NULL!=root->right) findMaxPathSum(root->right,max_path_sum);
    }
};