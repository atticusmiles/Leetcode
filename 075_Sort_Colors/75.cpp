#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
    	int len = nums.size();
    	int last_0 = -1;
    	int first_3 = len;
    	int i =0;
    	while(i<first_3)
    	{
   //  		for(int k=0; k<nums.size(); ++k)
			// {
			// 	if(k==i) cout<<"*";
			// 	cout<<nums[k]<<"\t";
			// }
			// cout<<endl;

    		if(1==nums[i])
    		{
    			++i;
    		}
    		else if(0==nums[i])
    		{
    			if(last_0>=i) 
    			{
    				++i;
    				continue;
    			}
    			swap(nums[i],nums[++last_0]);
    			continue;
    		}
    		else
    		{
    			swap(nums[i],nums[--first_3]);
    			continue;
    		}
    	}

    }
};



int main()
{
	vector<int> nums {0,0,0,1,1,0,0,0,1,2,1,0,2,1,0};
	// vector<int> nums{0};
	Solution slt;
	for(auto i: nums)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	slt.sortColors(nums);
	for(auto i: nums)
	{
		cout<<i<<"\t";
	}
	cout<<endl;
	while(1);
}