#include <vector>
using namespace std;


class Solution {
public:
    int removeElement(vector<int>& nums, int val) 
    {
        auto iter = nums.begin();
   		while(iter!=nums.end())
   		{
   			if(val == *iter)
   			{
   				nums.erase(iter);
   			}
   			else
   			{
   				++iter;
   			}
   		}
		return nums.size();
    }
};