#include "../data_type.h"

class Solution1 {
public:
    void reorderList(ListNode* head) 
    {
    	if(NULL == head) return;
    	int i = 0;
    	ListNode* tail = head;
    	ListNode* prev = NULL;
    	while(NULL!= tail->next)
    	{
    		prev = tail;
    		tail=tail->next;
    		++i;
    	}
    	if(i<2) return;
    	tail->next = head->next;
    	prev->next = NULL;
    	head->next = tail;
    	reorderList(head->next->next);
    }
};

class Solution2 {
public:
    void reorderList(ListNode* head) 
    {
    	if(NULL == head) return;

    	int len = 0;
    	ListNode* tail = head;

    	while(NULL!= tail)
    	{
    		tail=tail->next;
    		++len;
    	}
    	if(len<2) return;
    	int half = (len+1)/2;

    	ListNode* right_head = head;
    	for(int i=0; i <half-1; ++i)
    	{
    		right_head = right_head->next;
    	}
		ListNode* this_node = right_head;
		right_head = right_head->next;
		this_node->next = NULL;
		this_node = right_head;
    	ListNode* prev = NULL;
    	while(NULL!=this_node)
    	{
    		auto tmp = this_node;
    		this_node = this_node->next;
    		tmp->next = prev;
    		prev = tmp;
    	}
    	right_head = prev;


    	ListNode* right_iter = right_head;
    	ListNode* left_iter = head;
    	while(right_iter!=NULL)
    	{
    		ListNode* left_next = left_iter->next;
    		ListNode* right_next = right_iter->next;
    		left_iter->next=right_iter;
    		right_iter->next=left_next;
    		left_iter = left_next;
    		right_iter = right_next;
    	}
    }
};