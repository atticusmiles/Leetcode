
//Definition for a binary tree node.

#include <stdlib.h>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) 
    {
    	vector <TreeNode*> CurrentLevel;
    	vector <TreeNode*> NextLevel;

    	vector <vector<int>> dest;

    	if (!root) return dest; 

    	NextLevel.push_back(root);

    	while (0!=NextLevel.size())
    	{
    		vector<int> level;
    		CurrentLevel.clear();
    		CurrentLevel.swap(NextLevel);   		
    		for (auto node=CurrentLevel.begin(); node<CurrentLevel.end(); ++node)
    		{
    			level.push_back((*node)->val);
    			if ((*node)->left) NextLevel.push_back((*node)->left);
    			if ((*node)->right) NextLevel.push_back((*node)->right);
    		}
    		dest.push_back(level);
    	}
    	return dest;
    }
};
