#include "../data_type.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) 
    {
    	if(NULL==head) return NULL;
        ListNode header(0);
        header.next = head;

        ListNode* ptr=&header;
        while(NULL!=ptr->next && NULL!=ptr->next->next)
        {
        	ListNode* nxt = ptr->next->next->next;
        	ListNode* tmp = ptr->next;
        	ptr->next=ptr->next->next;
        	ptr->next->next=tmp;
        	ptr->next->next->next=nxt;
        	ptr=ptr->next->next;
        }
        return header.next;
    }
};

int main()
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

	head = slt.swapPairs(head);
	head->print();
	while(1);
	return 1;
}