#
# @lc app=leetcode id=20 lang=python3
#
# [20] Valid Parentheses
#
# https://leetcode.com/problems/valid-parentheses/description/
#
# algorithms
# Easy (38.12%)
# Likes:    4243
# Dislikes: 199
# Total Accepted:    874.9K
# Total Submissions: 2.3M
# Testcase Example:  '"()"'
#
# Given a string containing just the characters '(', ')', '{', '}', '[' and
# ']', determine if the input string is valid.
# 
# An input string is valid if:
# 
# 
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# 
# 
# Note that an empty string is also considered valid.
# 
# Example 1:
# 
# 
# Input: "()"
# Output: true
# 
# 
# Example 2:
# 
# 
# Input: "()[]{}"
# Output: true
# 
# 
# Example 3:
# 
# 
# Input: "(]"
# Output: false
# 
# 
# Example 4:
# 
# 
# Input: "([)]"
# Output: false
# 
# 
# Example 5:
# 
# 
# Input: "{[]}"
# Output: true
# 
# 
#

# @lc code=start
class Solution:
    def isValid(self, s: str) -> bool:
        
        opening = {
            "[" : "]",
            "{" : "}",
            "(" : ")"
        }

        stack = []

        for char in s : 
            if char in opening :
                stack.append(char)
                continue
            elif len(stack) > 0 and char == opening[stack[len(stack)-1]] : 
                stack.pop()
                continue
            else : 
                return False

        return len(stack) == 0


# @lc code=end

