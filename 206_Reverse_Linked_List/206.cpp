#include <stdlib.h>
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 

class Solution {
public:
    ListNode* reverseList(ListNode* head) 
    {
      if(NULL==head) return NULL;
      if(head->next==NULL) return head;
      ListNode* tail=head->next;
      ListNode* reverse_head=reverseList(head->next);
      tail->next=head;
      tail->next->next=NULL;
      return reverse_head;
    }
};

// class Solution {
// public:
//     ListNode* reverseList(ListNode* head) 
//     {
//     	ListNode * tmp;
//     	ListNode * prev=NULL;
//     	ListNode * iter=head;
//     	while(iter)
//     	{
//     		tmp=iter->next;
//     		iter->next=prev;
//     		prev=iter;
//     		iter=tmp;
//     	}
//     	return prev;
//     }
// };

