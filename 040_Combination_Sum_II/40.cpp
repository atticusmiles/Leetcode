#include <iostream>
#include <vector>
#include <set>
using namespace std;


class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        // vector<vector<int>> res;
        set<vector<int>> res_tmp;
        vector<int> combination;
        findcombination(candidates,combination,target,0,res_tmp);
        return vector<vector<int>> (res_tmp.begin(),res_tmp.end());
    }

    void findcombination(vector<int> &candidates, vector<int>&combination, int target, int position, set<vector<int>> &res_tmp)
    {
        if(target>0) 
        {
            for (int i = position; i<candidates.size(); ++i)
            {   
                int temp_target = target - candidates[i];
                if(temp_target<0) return;
                if(i&&candidates[i]==candidates[i-1]&&i>position) continue;
                combination.push_back(candidates[i]);
                findcombination(candidates,combination,temp_target,i+1,res_tmp);
                combination.pop_back();
            }
        }
        else
        {
            res_tmp.insert(combination);
            return;
        }   
    }
};

int main()
{
    Solution slt;
    vector<int> nums{10,1,2,7,6,1,5};
    // vector<int> nums{2};
    int val=8;
    vector<vector<int>> res = slt.combinationSum2(nums, val);
    for(auto &v: res)
    {
        for(auto i: v)
        {
            cout<<i<<"\t";
        }
        cout<<endl;
    }
    while(1);
}