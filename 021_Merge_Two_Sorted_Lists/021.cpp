#include <stdlib.h>
#include <iostream>
#include <vector>
using namespace std;

// * Definition for singly-linked list.
  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };
 
//  Last executed input:
// [-10,-10,-9,-4,1,6,6], [-7]
// 

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
    {
    	//deal with NULL situations
    	if(NULL==l1)
    	{
    		return l2;
    	}
    	if(NULL==l2)
    	{
    		return l1;
    	}

    	ListNode* head = (l1->val<l2->val)? l1 : l2 ;
        ListNode* line = (l1->val<l2->val)? l2 : l1 ;
        ListNode* iter = head;

        while(line)
        {
            while(iter->next!=NULL && iter->next->val<line->val)
            {
                iter=iter->next;
            }
            ListNode* tmp = iter->next;
            iter->next=line;
            line=line->next;
            iter->next->next = tmp;          
        }

        return head;

    }
};

int main()
{
    ListNode * l1_1 = new ListNode(-10);
    ListNode * l1_2 = new ListNode(-10);
    ListNode * l1_3 = new ListNode(-9);
    ListNode * l1_4 = new ListNode(-4);
    ListNode * l1_5 = new ListNode(-1);
    ListNode * l1_6 = new ListNode(6);
    ListNode * l1_7 = new ListNode(6);
    ListNode * l2_1 = new ListNode(-7);

    l1_1->next=l1_2;
    l1_2->next=l1_3;
    l1_3->next=l1_4;
    l1_4->next=l1_5;
    l1_5->next=l1_6;
    l1_6->next=l1_7;

    Solution slt;
    ListNode * result = slt.mergeTwoLists(l1_1,l2_1);

    while(result!=NULL)
    {
//        cout<<"res"<<endl;
        cout<<result->val<<"\t";
        result=result->next;
    }
    cout<<endl;
    while(1);

}

