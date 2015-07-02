#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
    	auto iter= nums.begin();
    	
    	if(nums.size()==0) return 0;

    	while(1)
    	{
    		if (nums.end()==(iter+1))
    		{
    			break;
    		}
    		else
    		{
    			if (*iter==*(iter+1))
    			{
    				nums.erase(iter);
    			}
    			else
    			{
    				++iter;
    			}
    		}
    	}
    	return nums.size();
    }
};

int main()
{
	vector<int> ivec{1,1,1,2,3,4,5,5,5,7,7,9,10};
	Solution slt;
	cout<<slt.removeDuplicates(ivec)<<endl;
	for (auto c: ivec)
	{
		cout<<c<<"\t";
	}
	cout<<endl;
	while(1);
}