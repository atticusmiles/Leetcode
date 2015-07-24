#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) 
    {
    	int seed = 0;
    	int max = nums.front();

    	for(int i = 0; i<nums.size(); ++i)
    	{
    		seed += nums[i];

    		max = (max<seed)? seed : max;
    		
    		if(seed<0) 
    		{
    			seed = 0;
    		}

    	}
    	return max;
    }
};


int main()
{
	vector<int> data{-2,-1};
	Solution slt;
	cout<<slt.maxSubArray(data)<<endl;
	while(1);
}