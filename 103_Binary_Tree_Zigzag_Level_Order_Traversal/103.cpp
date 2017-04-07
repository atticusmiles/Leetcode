#include <vector>
#include "../data_type.h"
using namespace std;


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) 
    {
    	vector <TreeNode*> CurrentLevel;
    	vector <TreeNode*> NextLevel;

    	vector <vector<int>> dest;

    	if (!root) return dest; 

    	NextLevel.push_back(root);
    	bool flag = 1;
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
    		if(flag)
    		{
    			flag = 0;
    		}
    		else
    		{
    			reverse(level.begin(),level.end());
    			flag = 1;
    		}
    		dest.push_back(level);
    	}
    	return dest;
    }
};