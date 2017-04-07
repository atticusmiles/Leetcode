#include "../data_type.h"
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
    {
    	ListNode* iter1 = l1;
    	ListNode* iter2 = l2;
    	ListNode* head = new ListNode(0);
    	ListNode* tail = head;

    	int flag=0;
    	int val1,val2;
    	int sum;
    	while(iter1 || iter2)
    	{
    		ListNode* digit;
    		if(iter1)
    		{
    			digit =iter1;
    			val1 = iter1->val;
    			iter1=iter1->next;

    		}
    		else
    		{
    			digit=iter2;
    			val1 = 0;
    		}

    		if(iter2)
    		{
    			val2 = iter2->val;
    			iter2 = iter2->next;
    		}
    		else
    		{
    			val2 = 0;
    		}
    		sum=val1+val2+flag;
			digit->val=(sum%10);
    		flag  = sum/10;
    		tail->next=digit;
    		tail=tail->next;
    		tail->next=NULL;
    	}
    	if (flag) 
    	{
    		ListNode* digit = new ListNode(flag);
    		tail->next = digit;
    	}
    	return head->next;
    }
};