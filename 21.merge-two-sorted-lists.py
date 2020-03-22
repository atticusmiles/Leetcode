#
# @lc app=leetcode id=21 lang=python3
#
# [21] Merge Two Sorted Lists
#
# https://leetcode.com/problems/merge-two-sorted-lists/description/
#
# algorithms
# Easy (51.49%)
# Likes:    3436
# Dislikes: 508
# Total Accepted:    865.3K
# Total Submissions: 1.7M
# Testcase Example:  '[1,2,4]\n[1,3,4]'
#
# Merge two sorted linked lists and return it as a new list. The new list
# should be made by splicing together the nodes of the first two lists.
# 
# Example:
# 
# Input: 1->2->4, 1->3->4
# Output: 1->1->2->3->4->4
# 
# 
#

# @lc code=start
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        node1 = l1
        node2 = l2 
        head = ListNode(0)
        tail = head

        while(node1 !=None and node2 != None) :
            if node1.val >= node2.val:
                tail.next = node2
                node2 = node2.next
            else :
                tail.next = node1
                node1 = node1.next
            
            tail = tail.next
        else :
            if node1 == None :
                tail.next = node2 
            else :
                tail.next = node1

        return head.next


# @lc code=end

