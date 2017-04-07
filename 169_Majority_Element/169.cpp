#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
    	unordered_map <int,int> num_count;
    	int len = nums.size();
    	for (auto c: nums)
    	{
    		if(++num_count[c]>len/2) return c;
    	}
    }
};