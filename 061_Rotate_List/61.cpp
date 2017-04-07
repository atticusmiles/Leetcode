#include "../data_type.h"

//NOTE! ALWAYS CONSIDER THE NULL SITUATION FIRST!!!!
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