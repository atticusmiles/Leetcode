// string constructor
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include "data_type.h"

using namespace std;

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) 
    {
    	vector<int> path;
    	vector<vector<int>> result;
    	findPath(root, sum, path, result);
    	return result;
    }
    void findPath(TreeNode* root, int sum, vector<int> &path, vector<vector<int>> &result)
    {
    	path.push_back(root->val);
    	if(NULL==root->left && NULL==root->right)
    	{
    		if(sum==root->val) 
    		{
    			result.push_back(path);
    		}
    	}
    	else
    	{
    		if(NULL!=root->left)
    		{
    			findPath(root->left, sum-root->val, path, result);
    		}
    		if(NULL!=root->right)
    		{
    			findPath(root->right, sum-root->val, path, result);
    		}
    	}
    	path.pop_back();
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

	Solution slt;
	// head->print();
	root->print();
	vector<vector<int>> res = slt.pathSum(root, 11);

	for(auto &v : res)
	{
		for(auto i : v)
		{
			cout<<i<<"\t";
		}
		cout<<endl;
	}

	cout<<"done"<<endl;
	while(1);
	return 1;
}


