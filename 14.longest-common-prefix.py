#
# @lc app=leetcode id=14 lang=python3
#
# [14] Longest Common Prefix
#
# https://leetcode.com/problems/longest-common-prefix/description/
#
# algorithms
# Easy (34.73%)
# Likes:    2105
# Dislikes: 1697
# Total Accepted:    657.1K
# Total Submissions: 1.9M
# Testcase Example:  '["flower","flow","flight"]'
#
# Write a function to find the longest common prefix string amongst an array of
# strings.
# 
# If there is no common prefix, return an empty string "".
# 
# Example 1:
# 
# 
# Input: ["flower","flow","flight"]
# Output: "fl"
# 
# 
# Example 2:
# 
# 
# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.
# 
# 
# Note:
# 
# All given inputs are in lowercase letters a-z.
# 
#

# @lc code=start
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if(len(strs)==0 ) : 
            return ""
        
        prefix = strs[0]
        for s in strs:
            while len(prefix) > 0 : 
                if s.startswith(prefix) :
                    break
                else :
                    prefix = prefix[:len(prefix)-1]
            else:
                return ""

        return prefix

# @lc code=end

