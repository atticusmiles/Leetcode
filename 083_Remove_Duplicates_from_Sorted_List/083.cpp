#include <iostream>
  // Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
    	if (NULL==head) return NULL;
    	ListNode* header = new ListNode(0);
    	header->next = head;
    	ListNode* iter=header;
    	while(NULL!= iter->next->next)
    	{
    		if (iter->next->val == iter->next->next->val)
    		{
    			iter->next=iter->next->next;
    		}
    		else
    		{
    			iter=iter->next;
    		}
    	}
    	return header->next;
    }
};