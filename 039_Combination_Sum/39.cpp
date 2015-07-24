#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> combinations;
        sort(candidates.begin(),candidates.end());
        vector<int> path;
        findCombination(candidates,path,0,target,combinations,0);
        return combinations;
    }

    void findCombination(vector<int>& candidates, vector<int> path, int path_sum, int &target, vector<vector<int>> &combinations, int progress)
    {
        for (int i=progress+1; i<candidates.size(); ++i)
        {
            // while((i>0 && candidates[i-1]==candidates[i]))
            // {
            //     ++i;
            // }

            int path_sum_temp = path_sum + candidates[i];
            if(target <= path_sum_temp ) return;
            else
            {
                vector<int> path_tmp = path;
                path_tmp.push_back(candidates[i]);
                if(target==path_sum_temp) combinations.push_back(path_tmp);
                else
                {
                    findCombination(candidates,path_tmp,path_sum_temp,target,combinations,i);
                }
            }
        }
    }
};

// class Solution {
// public:
//     vector<vector<int> > combinationSum(vector<int> &candidates, int target) 
//     {
//         sort(candidates.begin(), candidates.end());
//         vector<vector<int> > res;
//         vector<int> combination;
//         combinationSum(candidates, target, res, combination, 0);
//         return res;
//     }
// private:
//     void combinationSum(vector<int> &candidates, int target, vector<vector<int> > &res, vector<int> &combination, int begin) {
//         if  (!target) {
//             res.push_back(combination);
//             return;
//         }
//         for (int i = begin; i != candidates.size() && target >= candidates[i]; ++i) {
//             combination.push_back(candidates[i]);
//             combinationSum(candidates, target - candidates[i], res, combination, i);
//             combination.pop_back();
//         }
//     }
// };

int main()
{
	Solution slt;
	vector<int> nums{5,10,8,4,3,12,9};
    // vector<int> nums{2};
	int val=27;
	vector<vector<int>> res = slt.combinationSum(nums, val);
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