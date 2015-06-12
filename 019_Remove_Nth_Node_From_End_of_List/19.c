
 //* Definition for singly-linked list.
 struct ListNode {
   int val;
   struct ListNode *next;
 };
 
#include <stdlib.h>

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) 
{
	struct ListNode * ProbeNode=head;
//	struct ListNode * TargetNode=head;
	struct ListNode * header=malloc(sizeof(struct ListNode));
	struct ListNode * BeforeTargetNode=header;
	BeforeTargetNode->val=0;
	BeforeTargetNode->next=head;

	for (int i=0 ; i<n-1 ; ++i)
	{
		ProbeNode=ProbeNode->next;
	}

	while(NULL!=ProbeNode->next)
	{
		BeforeTargetNode=BeforeTargetNode->next;
		ProbeNode=ProbeNode->next;
	}

	if (head==BeforeTargetNode->next)
	{
		return head->next;
	}
	else
	{
		BeforeTargetNode->next=BeforeTargetNode->next->next;
		return head;
	}

}