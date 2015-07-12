#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
    	unordered_map <int,int> checked;
    	vector<int> result;
    	for(int i=0; i<nums.size(); ++i)
    	{
    		auto iter=checked.find(target-nums[i]);
	    	if(checked.end()==iter)
	    	{
	    		checked.insert(pair<int,int>(nums[i],i));
	    	}
	    	else
	    	{
	    		result.push_back((*iter).second +1);
	    		result.push_back(i+1);
	    		return result;
	    	}
    	}
    	return result;
    }
};
