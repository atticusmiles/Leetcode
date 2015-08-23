#include "../data_type.h"

class Solution {
public:
    bool hasCycle(ListNode *head) 
    {
    	if(NULL==head) return false;

        ListNode* slow = head;
        ListNode* fast = head;
        bool isEvenNode = 1;
        while(fast)
        {
        	fast = fast->next;
        	isEvenNode=!isEvenNode;
        	if(isEvenNode) slow=slow->next;
        	if(fast==slow) return true;
        }
        return false;
    }
};