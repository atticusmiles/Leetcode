#include <set>
#include <vector> 
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {

        sort(nums.begin(),nums.end());
    	vector<vector<int>> result;
    	vector<int> combination;
    	findSubset(combination,nums,result,-1);
    	return result;
    }
    void findSubset(vector<int> &combination, vector<int> &nums, vector<vector<int>> &res, int progress)
    {
        int src_cnt = 1;
        int dst_cnt = 1;
        int dst_size = combination.size();
        while(dst_size>dst_cnt && combination[dst_size-dst_cnt]==combination[dst_size-dst_cnt-1]) ++dst_cnt;
        while(progress+1>src_cnt && nums[progress+1-src_cnt]==nums[progress-src_cnt]) ++src_cnt;
        if(src_cnt!=dst_cnt) return;
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
    vector<int> nums{1,1,2,3};
    vector<vector<int>> res = slt.subsetsWithDup(nums);
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