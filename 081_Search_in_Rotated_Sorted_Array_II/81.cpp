#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) 
    {
    	int lo =0, hi = nums.size()-1;
        int mid = 0;
        while(lo<hi)
        {
            mid=(lo+hi)/2;
            if(nums[mid]==target) return true;
            if(nums[mid]>nums[hi])//左边是排序的
            {
                if(nums[mid]>target && nums[lo] <= target) hi = mid; //目标在左边,把右界设在中间
                else lo = mid + 1;//目标在右边,把左界设在中间
            }
            else if(nums[mid] < nums[hi])//右边是排序的
            {
                if(nums[mid]<target && nums[hi] >= target) lo = mid + 1;//目标在右边,把左界设在中间
                else hi = mid;//目标在左边,把右界设在中间
            }
            else
            {
                hi--;
            }
        }
        return nums[lo] == target ? true : false;
    }
};


int main()
{
    Solution slt;
    // vector<int> nums{8,8,8,8,8,8,1,1,1,1,1,1,2,2,2,2,2,2,3,4,5,6,8};
    vector<int> nums{2,2,2,0,2,2};
    cout<<slt.search(nums,2)<<endl;
    while(1);
}