#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     bool canJump(vector<int>& nums) 
//     {
//     	return isViable(0,nums);
//     }
//     bool isViable(int i,vector<int>&nums)
//     {
//     	if(nums[i]+i>=(nums.size()-1)) return true;
//     	if(0==nums[i]&i<nums.size()-1) return false;
    	
// 		for(int k=i+nums[i]; k>i; --k )
// 		{
// 			if(isViable(k,nums)) return true;
// 		}
// 		return false;
//     }
// };
class Solution {
public:
    bool canJump(vector<int>& nums) 
    {
    	int n = 0;
    	int len = nums.size();
    	int reach =0;
    	for(; n<len &&n<=reach; ++n)
    	{
    		reach = max(reach, n+nums[n]);
    	}
    	return n==len-1;
    }
};


int main()
{
	vector<int> nums{3,2,1,0,4};
	Solution slt;
	cout<<slt.canJump(nums)<<endl;
	while(1);
}