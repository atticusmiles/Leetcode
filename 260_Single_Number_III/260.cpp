#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) 
    {
    	if(0==nums.size()) return vector<int>();

    	int all_xor = 0;
    	for(auto i : nums)
    	{
    		all_xor ^= i;
    	}

    	int last_1 = ((all_xor-1)&all_xor)^all_xor;

    	int bit_1_xor = 0;
    	int bit_0_xor = 0;

    	for(auto i : nums)
    	{
    		if(i & last_1) 
    		{
    			bit_1_xor ^= i;
    		}
    		else
    		{
    			bit_0_xor ^= i;
    		}
    	}
    	return vector<int>{bit_1_xor,bit_0_xor};
    }
};