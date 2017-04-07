#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        vector<int> res;
        int tmp = 1;
        res.push_back(1);
        for (int i = 0; i<nums.size()-1; ++i)
        {
        	tmp*=nums[i];
        	res.push_back(tmp);
        }
        tmp = 1;
        for (int i = nums.size()-1; i>=0; --i)
        {
        	res[i]*=tmp;
        	tmp*=nums[i];
        }
        return res;

    }
};