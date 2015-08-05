#include "../data_type.h"
#include <vector>
using namespace std;

typedef vector<int>::iterator iiter;
class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) 
    {
    	return createBST(nums.begin(),nums.end());
    }
    TreeNode* createBST(iiter begin, iiter end)
    {
    	if(begin==end) return NULL;
    	//when even, prefer the right node
    	iiter mid = begin+(end-begin)/2;
    	TreeNode* this_node = new TreeNode(*mid);
    	this_node->left = createBST(begin,mid);
    	this_node->right = createBST(mid+1,end);
    	return this_node;
    }
};