#include <stdlib.h>
#include <vector>
#include <deque>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) 
    {
        vector <TreeNode*> CurrentLevel;
    	vector <TreeNode*> NextLevel;

    	deque <vector<int>> dest;
    	vector<vector<int>> null_vec;
    	
    	if (!root) return null_vec; 

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
    		dest.push_front(level);
    	}
    	vector<vector<int>> output(dest.begin(),dest.end());
    	return output;
    }
};