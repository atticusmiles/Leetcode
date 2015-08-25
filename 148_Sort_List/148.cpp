#include "../data_type.h"
using namespace std;

class Solution {
public:
    ListNode* sortList(ListNode* head) 
    {
        if(NULL==head || NULL == head->next) return head;
        ListNode* fast = head;
        ListNode* slow = head;
        bool flag = false;
        while(fast->next)
        {
            fast = fast->next;
            if(flag) slow = slow->next;
            flag = !flag;
        }
        ListNode* l1 = head;
        ListNode* l2 = slow->next;
        slow->next = NULL;
        l1 = sortList(l1);
        l2 = sortList(l2);
        ListNode* new_head = merge(l1,l2);
        return new_head;
    }

    ListNode* merge(ListNode* l1, ListNode* l2)
    {
        ListNode header(INT_MIN);
        ListNode* tail = &header;
        ListNode* iter1 = l1;
        ListNode* iter2 = l2;
        while(iter1!=NULL && iter2!=NULL)
        {
            ListNode* &node_taken = (iter1->val < iter2->val)? iter1 : iter2;
            ListNode* this_node = node_taken;
            node_taken = node_taken->next;
            this_node->next = NULL;
            tail->next = this_node;
            tail = tail->next;
        }
        ListNode* remaining_list = (iter1==NULL)? iter2 : iter1;
        tail->next = remaining_list;
        return header.next;
    }
};