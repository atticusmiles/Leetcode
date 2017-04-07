// string constructor
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include "data_type.h"

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
    }
};
int main ()
{
	ListNode list[30];
	for(int i=0; i<29; ++i)
	{
		list[i].val=i;
		list[i].next=&list[i+1];
	}
	list[29].val=29;
	ListNode *head = &list[0];

	//Initiate Trees
	TreeNode tree[15];
	for(int i=0; i<15; ++i)
	{
		tree[i].val=i;
	}

	tree[0].left=&tree[1];tree[0].right=&tree[2];
	tree[1].left=&tree[3];tree[1].right=&tree[4];tree[2].left=&tree[5];tree[2].right=&tree[6];
	tree[3].left=&tree[7];tree[3].right=&tree[8];tree[4].left=&tree[9];tree[4].right=&tree[10];tree[5].left=&tree[11];tree[5].right=&tree[12];tree[6].left=&tree[13];tree[6].right=&tree[14];
	TreeNode* root = &tree[0];

	TreeNode* new_root= new TreeNode(-2);
	TreeNode* new_left= new TreeNode(1);
	new_root->left=new_left;

	Solution slt;
	// head->print();
	TreeNode* sumTree;
	slt.maxUpPathSum(new_root, sumTree);
	root->print();
	// sumTree->print();
	// new_root->print();

	// for(auto &v : res)
	// {
	// 	for(auto i : v)
	// 	{
	// 		cout<<i<<"\t";
	// 	}
	// 	cout<<endl;
	// }

	cout<<"done"<<endl;
	while(1);
	return 1;
}


