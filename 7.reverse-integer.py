#
# @lc app=leetcode id=7 lang=python3
#
# [7] Reverse Integer
#

# @lc code=start
class Solution:
    def reverse(self, x: int) -> int:
        sign = ""
        if x<0 : 
            sign = "-"
        unsigned = str(abs(x))
        transformed = int(sign + unsigned[::-1]) 
        if transformed > (2**31 -1) or transformed < -2**31  : 
            return 0
        else :
            return transformed

# @lc code=end

