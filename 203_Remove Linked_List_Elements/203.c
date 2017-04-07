
//  Definition for singly-linked list.
  struct ListNode {
      int val;
      struct ListNode *next;
  };
  
#include <stdlib.h>

struct ListNode* findPrev(struct ListNode* head, int val)
{
	struct ListNode* ptrNode=head->next;
	struct ListNode* ptrPrev=head;
	while (NULL!=ptrNode)
	{
		if (val==ptrNode->val)
		{
			return ptrPrev;
		}
		else
		{
			ptrPrev=ptrNode;
			ptrNode=ptrNode->next;
		}
	}
	return ptrNode;
}

struct ListNode* removeElements(struct ListNode* head, int val) 
{
    if (!head) return head;
    
    struct ListNode* header=malloc(sizeof(struct ListNode));
    struct ListNode* ptrNode;
    struct ListNode* ptrPrev;
    struct ListNode* ptrTemp;

    header->next=head;
    header->val=0;

    ptrNode=header;

    while(NULL!=ptrNode->next )
    {
    	if (NULL!=(ptrPrev=findPrev(ptrNode,val)))
    	{
    		ptrTemp=ptrPrev->next;
    		ptrPrev->next=ptrTemp->next;
    		free(ptrTemp);
    		ptrNode=ptrPrev;
    	}
    	else
    	{
    		break;
    	}
    }
    return header->next;
}

