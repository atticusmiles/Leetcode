#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
    	set<int> data;
    	for(auto c: nums)
    	{
    		if(!data.insert(c).second) return true;
    	}
    	return false;
    }
};