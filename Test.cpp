// string constructor
#include <string>
#include <map>
#include <unordered_map>
#include "data_type.h"

using namespace std;


class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) 
    {
    	if(NULL==head) return NULL;

    	int len =1;
        ListNode* tail = head;
        while(tail->next) 
    	{
    		tail=tail->next;
    		++len;
    	}
    	int steps =(len-k%len);
        tail->next = head;

        ListNode* new_tail = tail;
        for(int i=0; i<steps; ++i)
        {
        	new_tail=new_tail->next;
        }

        ListNode* new_head = new_tail->next;

        new_tail->next = NULL;
        return new_head;
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
	slt.rotateRight(head, 2)->print();

	// root->print();



	while(1);
	return 1;
}


