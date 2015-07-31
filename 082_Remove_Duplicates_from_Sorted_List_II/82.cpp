#include "../data_type.h"

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) 
    {
		ListNode* header = new ListNode(0);
		header->next = head;
		ListNode* last_num = header;
		ListNode* iter=head;
		bool isSameAsLast = false;
		while(iter)
		{
			if(isSameAsLast)
			{
				if(iter->next==NULL || iter->next->val != iter->val)
				{
					last_num->next=iter->next;
					isSameAsLast=false;
				}
				iter=iter->next;
			}
			else
			{
				if(iter->next==NULL || iter->next->val!=iter->val)
				{
					last_num=iter;
				}
				else
				{
					isSameAsLast =true;
				}
				iter=iter->next;
			}
		}
		ListNode* res = header->next;
		delete header;
		return res;
    }
};