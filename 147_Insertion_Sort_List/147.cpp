#include "../data_type.h"

class Solution {
public:
    ListNode* insertionSortList(ListNode* head) 
    {
    	ListNode header(INT_MIN);
    	ListNode* this_node = head;
    	while(this_node)
    	{
    		ListNode* next_node = this_node->next;
    		ListNode* index = &header;
    		while(1)
    		{
    			if((index->next==NULL) ||(index->val<=this_node->val && index->next->val>this_node->val) )
    			{
    				ListNode* tmp = index->next;
    				index->next = this_node;
    				this_node->next = tmp;
    				break;
    			}
    			index=index->next;
    		}
    		this_node = next_node;
    	}
    	return header.next;
    }
};