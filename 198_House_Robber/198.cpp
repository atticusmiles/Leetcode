// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, 
// the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically 
// contact the police if two adjacent houses were broken into on the same night.
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight 
// without alerting the police.


#include <vector>

using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int max_chosen=0;
        int max_n_chosen=0;

        int tmp=0;

        for (auto iter= nums.begin(); iter<nums.end(); ++iter)
        {
        	tmp = max_n_chosen;
        	max_n_chosen= max_chosen>max_n_chosen? max_chosen : max_n_chosen;
        	max_chosen= tmp + *iter;
        }

        return max_chosen>max_n_chosen? max_chosen : max_n_chosen;
    }
};