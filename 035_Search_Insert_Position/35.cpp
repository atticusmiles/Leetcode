#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) 
    {
		int head=0;
    	int tail = nums.size()-1;
    	while(head<=tail)
    	{
    		int mid = (head + tail) / 2;
    		if(nums[mid]<target) head = mid+1;
    		else if(nums[mid]>target) tail = mid -1;
    		else return mid;
    	}
    	return head;
    }
};

int main()
{
	// vector<int> nums{0,1,2,3,4,5,7,8,9,10,11};
	vector<int> nums{1};
	int target = 2;
	Solution slt;
	cout<<slt.searchInsert(nums,target)<<endl;
	while(1);
}