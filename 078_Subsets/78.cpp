#include <vector> 
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) 
    {
    	sort(nums.begin(),nums.end());
    	vector<vector<int>> result;
    	vector<int> combination;
    	findSubset(combination,nums,result,-1);
    	return result;
    }
    void findSubset(vector<int> &combination, vector<int> &nums, vector<vector<int>> &res, int progress)
    {
    	res.push_back(combination);
    	for(int i = progress+1; i<nums.size(); ++i)
    	{
    		combination.push_back(nums[i]);
    		findSubset(combination,nums,res,i);
    		combination.pop_back();
    	}
    }
};

int main()
{
	Solution slt;
	vector<int> nums{1,2,3};
	vector<vector<int>> res = slt.subsets(nums);
	for(auto &v:res)
	{
		for(auto &i: v)
		{
			cout<<i<<"\t";
		}
		cout<<endl;
	}
	while(1);
}