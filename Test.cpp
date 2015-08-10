// string constructor
#include <stack>
#include <string>
#include <map>
#include <unordered_map>
#include "data_type.h"

using namespace std;

class Solution {
public:
    void flatten(TreeNode* root) 
    {
    	stack<TreeNode*> nodes;
    	TreeNode* header = new TreeNode(0);
    	TreeNode* tail = header;
    	nodes.push(root);
    	preoder_tvs(nodes, tail);
    }
    void preoder_tvs(stack<TreeNode*> &cache, TreeNode* &tail)
    {
    	if(cache.size()==0) return;
    	else
    	{
    		TreeNode* this_node = cache.top();
    		tail->right = this_node;
    		tail = this_node;
    		cache.pop();
    		
    		if(NULL!= this_node->right) cache.push(this_node->right);
    		if(NULL!= this_node->left) cache.push(this_node->left);
    		
    		this_node->left = NULL;
    		this_node->right = NULL;
    	}
    	preoder_tvs(cache,tail);
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
	slt.flatten(root);
	root->print();

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


