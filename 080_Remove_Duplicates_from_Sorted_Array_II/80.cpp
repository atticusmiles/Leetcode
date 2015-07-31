#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
	int removeDuplicates(vector<int>& nums) 
    {
    	sort(nums.begin(),nums.end());
    	vector<bool> flags(nums.size(),1);
    	bool flag = 0;
    	for(int i=1; i<nums.size(); ++i)
    	{
    		if(nums[i]!=nums[i-1])
    		{
    			flag = 0;
    		}
    		else
    		{
    			if(flag == 0)
    			{
    				flag = 1;
    			}
    			else
    			{
    				flags[i] =0;
    			}
    		}
    		
    	}
    	vector<int> processed;
    	for(int i=0; i<nums.size(); ++i)
    	{
    		if(flags[i]) processed.push_back(nums[i]);
    	}
    	nums.swap(processed);
    	return nums.size();
    }
};

// int removeDuplicates(vector<int>& nums) 
//     {
//     	unordered_map <int,int> count;
//     	int dump_head = nums.size();
//     	int search_head = 0;
//     	while(search_head<dump_head)
//     	{	
//     		if(count[nums[search_head]]++>=2) swap(nums[search_head],nums[--dump_head]);
//     		else ++search_head;
//     	}
//     	sort(nums.begin(),nums.begin()+search_head);
//     	return search_head;
//     }

int main()
{
	vector<int> nums{1,1,1,1,1,3};
	for(auto i:nums) cout<<i<<"\t";
	cout<<endl;
	Solution slt;
	cout<<slt.removeDuplicates(nums)<<endl;;
	for(auto i:nums) cout<<i<<"\t";
	cout<<endl;
	cin.get();
}