#include <stdlib.h>
//Definition for a binary tree node.
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 
class Solution {
public:
	bool isReverse(TreeNode* p, TreeNode* q)
	{
		if (NULL==p || NULL==q)
		{
			if (p!=q) return false;
		}
		else
		{
			if (p->val != q->val) return false;
			if (!isReverse(p->left,q->right)) return false;
			if (!isReverse(p->right,q->left)) return false;
		}
		return true;	
	}

    bool isSymmetric(TreeNode* root) 
    {
 		if (!root) return true;
 		else return isReverse(root->left,root->right);
    }
};


// class Solution {
// public:
//     bool isSameTree(TreeNode* p, TreeNode* q) 
//     {
//     	if (NULL==p || NULL==q)
//     	{
//     		if (p!=q) return false;
//     	}
//     	else
//     	{
//     		if (p->val != q->val) return false;
//     		if (!isSameTree(p->left,q->left)) return false;
//     		if (!isSameTree(p->right,q->right)) return false;
//     	}
// 		return true;		
//     }
// };
