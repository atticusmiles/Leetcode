#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
    	sort(nums.begin(),nums.end());

    	int close_range = abs(nums[0]+nums[1]+nums[2]-target);
    	for(auto iter=nums.begin(); iter<nums.end(); ++iter  )
    	{
    		int head=(iter=nums.begin());
    		int rear=nums.size()-1;
			
			if()    		



    	}
    }
};