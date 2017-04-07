#include "../data_type.h"

class Solution {
public:
    ListNode *detectCycle(ListNode *head) 
    {
        if(NULL==head) return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        bool isEvenNode = 1;
        while(fast)
        {
        	fast = fast->next;
        	isEvenNode=!isEvenNode;
        	if(isEvenNode) slow=slow->next;
        	if(fast==slow)
        	{
        		int loop_len=1;
        		fast = fast->next;
        		while(fast!=slow)
        		{
        			fast = fast->next;
        			++loop_len;
        		}
        		fast = head;
        		slow = head;
        		for(int i=0; i<loop_len; ++i)
        		{
        			fast = fast->next;
        		}
        		while(fast!=slow)
        		{
        			fast=fast->next;
        			slow=slow->next;
        		}
        		return fast;
        	}
        }
        return NULL;
    }
};