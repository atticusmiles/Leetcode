#include "../data_type.h"

class Solution {
public:
    ListNode* partition(ListNode* head, int x) 
    {
    	if(NULL==head) return NULL;
    	ListNode* left_header = new ListNode(0);
    	ListNode* left_tail = left_header;
    	ListNode* right_header = new ListNode(0);
    	ListNode* right_tail = right_header;

    	ListNode* iter = head;
    	while(iter)
    	{
    		ListNode* this_node =iter;
    		iter=iter->next;

    		if(this_node->val<x)
    		{
    			left_tail->next = this_node;
    			left_tail=left_tail->next;
    		}
    		else
    		{
    			right_tail->next = this_node;
    			right_tail = right_tail->next;
    		}
    	}
    	left_tail->next = right_header->next;
    	right_tail->next = NULL;
    	return left_header->next;
    }
};