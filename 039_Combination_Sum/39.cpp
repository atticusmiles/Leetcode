#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
    	set<vector<int>> result;
    	set<pair<vector<int>,int>> routes;
		set<pair<vector<int>,int>> tmp_routes;

    	set<int> nums(candidates.begin(),candidates.end());

    	for(auto i: nums)
    	{
    		if(i>target) continue;
    		else
    		{
    			vector<int> val{i};
    			if(i==target) 
				{
					result.insert(val);
					continue;
				}
	    		int sum = i;
	    		pair<vector<int>,int> route = {val,sum};
	    		routes.insert(route);
    		}
    		
    	}


    	while(0!=routes.size())
    	{
    		for(auto route: routes)
    		{
       			for (auto i: nums)
    			{
    				auto tmp_route = route;
    				tmp_route.first.push_back(i);
    				tmp_route.second+=i;
    				if(tmp_route.second==target)
    				{	
    					sort(tmp_route.first.begin(), tmp_route.first.end());
    					result.insert(tmp_route.first);
    				}
    				else if(tmp_route.second<target)
    				{
    					tmp_routes.insert(tmp_route);
    				}

    			}
    		}
    		routes.swap(tmp_routes);
    		tmp_routes.clear();
    	}
    return vector<vector<int>> (result.begin(),result.end());
    }
};

int main()
{
	Solution slt;
	vector<int> nums{5,10,8,4,3,12,9};
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