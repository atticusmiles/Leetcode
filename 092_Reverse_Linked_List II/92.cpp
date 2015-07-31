#include "../data_type.h"

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
    	ListNode* header = new ListNode(0);
    	header->next = head;
    	ListNode* iter = header;
    	for (int i=1; i<m; ++i)
    	{
    		iter=iter->next;
    	}
    	ListNode* left_tail = iter;
    	ListNode* tmp_tail = iter->next;
    	ListNode* tmp_head = tmp_tail;
    	ListNode* right_head = tmp_tail->next;
    	if(NULL==tmp_tail) return head;
    	ListNode* this_node;
    	iter = tmp_tail;
    	for(int i=0; i<=(n-m); ++i)
    	{
    		this_node = iter;
    		iter = iter->next;
    		this_node->next = tmp_head;
    		tmp_head = this_node;
    	}
    	right_head = iter;
		
    	left_tail->next = tmp_head;
    	tmp_tail->next = right_head;
    	return header->next;
    }
};
