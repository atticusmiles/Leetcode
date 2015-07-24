#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) 
    {
    	vector<vector<int>> res;
    	for(int i = 0 ; i<nums.size(); ++i)
    	{
    		swap_element(nums,0, i);
    		findcombination(nums,0,res);
    		swap_element(nums,0, i);
    	}
    	return res;
    }
    void findcombination(vector<int>&nums, int progress, vector<vector<int>> &res)
    {
    	if (progress==nums.size()-1) 
    	{
    		res.push_back(nums);
    		return;
    	}
    	int progress_tmp = progress + 1;
    	for(int i = progress_tmp; i<nums.size(); ++i)
    	{
    		swap_element(nums,progress_tmp, i);
    		findcombination(nums,progress_tmp,res);
    		swap_element(nums,progress_tmp, i);
    	}
    }
    inline void swap_element(vector<int> &nums, int a, int b)
    {
    	if (a==b) return;
    	nums[a] = nums[a] ^ nums[b];
    	nums[b] = nums[a] ^ nums[b];
    	nums[a] = nums[a] ^ nums[b];
    }
};

int main()
{
	Solution slt;
	while(1)
	{
		string s;
		stringstream ss;
		cout<<"input vector:";
		getline(cin,s);
		cout<<"result:\n";
		vector<int> nums;
		int a;
		ss<<s;
		while(ss>>a) nums.push_back(a);
		vector<vector<int>> result = slt.permute(nums);
		for(auto &v:result)
		{
			for(auto &i: v)
			{
				cout<<i<<"\t";
			}
			cout<<endl;
		}
	}

}