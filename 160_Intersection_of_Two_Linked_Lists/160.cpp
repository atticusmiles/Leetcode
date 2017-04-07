#include <iostream>
using namespace std;
 //Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) 
    {
        if (!headA || !headB) return NULL;
        
        int length_a=0,length_b=0;

        for (ListNode* ptrA = headA; NULL!=ptrA->next; ptrA=ptrA->next)
        {
        	++length_a;
        }

        for (ListNode* ptrB = headB; NULL!=ptrB->next; ptrB=ptrB->next)
        {
        	++length_b;
        }

       	ListNode * list_long = (length_a>length_b)? headA:headB;
       	ListNode * list_short = (length_a>length_b)? headB:headA;

       	for (int i=0; i<(abs(length_a-length_b)); ++i)
       	{
       		list_long=list_long->next;
       	}

       	while(1)
       	{
       		if (list_long==list_short) return list_long;
       		list_long=list_long->next;
       		list_short=list_short->next;
       	}
    }
};