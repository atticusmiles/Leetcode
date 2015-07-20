// string constructor
#include <string>
#include <map>
#include <unordered_map>
#include "data_type.h"

using namespace std;

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) 
    {
    	if(NULL==root) return NULL;

    	TreeNode* tmp=root->left;
    	root->left = invertTree(root->right);
    	root->right = invertTree(tmp);

    	return root;
    }
};

int main ()
{
	//Initiate List
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
	root=slt.invertTree(root);
//	root->print();
	unsigned int a =0xfffffff7;
	unsigned char i = (unsigned char) a ;
	char *b =(char*) &a ;
	printf("%08x, %08x",i,*b );
	while(1);
	return 1;
}


