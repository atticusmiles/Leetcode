#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) 
    {
        if(nums.size()==0) return 0;
        int global_max;
        int local_max;
        int local_min;
        int i;
        for(i=1, global_max=nums[0], local_min=nums[0], local_max=nums[0]; i<nums.size(); ++i)
        {
        	if(nums[i]<0)
        	{
        		swap(local_min,local_max);
        	}
        	local_min = min (local_min*nums[i],nums[i]);
        	local_max = max (local_max*nums[i],nums[i]);

            global_max = max(global_max,local_max);
        }
        return global_max;
    }
};

int main()
{
    
}