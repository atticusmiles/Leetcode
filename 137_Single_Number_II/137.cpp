#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) 
    {
    	int bit_num = sizeof(int)*8;
    	vector<int> bit_count(bit_num,0);
    	for(auto i : nums)
    	{
    		for(int k=0; k<bit_num; ++k)
    		{
    			if(i&(1<<k)) ++bit_count[k];
    		}
    	}

    	int res = 0;

    	for(int k=0; k<bit_num; ++k)
    	{
    		if(bit_count[k]%3) 
			{
				res|= (1<<k);
			}
    	}
    	return res;
    }
};