#include <vector>
using namespace std;

class Solution {
public:
    int findMin(vector<int>& nums) 
    {
    	if(nums.size()==0) return 0;
    	if(nums.front() <nums.back()) return nums.front();

    	int head = 0;
    	int tail = nums.size() - 1;

    	while(head<(tail-1))
    	{
    		int mid = (head + tail) / 2 ;
    		if(nums[mid]<nums[head]) 
			{
				tail = mid;
			}
    		else
    		{
    			head = mid;
    		}
    	}
    	return nums[tail];
    }
};