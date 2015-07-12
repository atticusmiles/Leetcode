#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) 
    {
        int r = k % nums.size();

        int pin = 0;
        int dock = nums[pin];
        int tmp;
        int position = (r+pin)%nums.size();

        for (int i=0; i<nums.size(); ++i)
        {
        	tmp = nums[position];
        	nums[position]=dock;
        	dock=tmp;
        	position=(position+r)%nums.size();
        	if(position==pin+r)
        	{
        		++pin;
        		dock=nums[pin];
        		position=(pin+r)%nums.size();
        	}
        }
    }
};

int main()
{
	vector<int> nums{0,1,2,3,4,5,6,7,8,9,10};
	Solution slt;
	slt.rotate(nums, 2);
	for(auto c: nums)
	{
		cout<<c<<"\t"<<flush;
	}
	while(cin>>nums[1]);
}