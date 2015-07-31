#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    inline int getRealPos(int ori_pos, int size, int start)
    {
        return (ori_pos+start+size)%(size);
    }
    int search(vector<int>& nums, int target) 
    {
    	int head = 0;
    	int tail = nums.size()-1;
        int start = 0;
        if(nums.front()<nums.back()) start =0;
        else
        {
            while(head<tail)
            {
                // cout<<head<<","<<tail<<endl;
                int middle = (head+tail)/2;
                if(nums[middle]>nums[head]) 
                {
                    head = middle;
                }
                else
                {
                    tail = middle;
                }
            }
            start = head +1;
        }
       
        
        // cout<<"start"<<start<<endl;
        head = 0;
        tail=nums.size()-1;
        while(head<=tail)
        {
            int middle = (head+tail)/2;
            if(nums[getRealPos(middle,nums.size(),start)]>target)
                tail = middle -1;
            else if(nums[getRealPos(middle,nums.size(),start)]<target)
                head = middle +1;
            else 
                return getRealPos(middle,nums.size(),start);
        }
        return -1;
    }
};

int main()
{
    Solution slt;
    vector<int> nums{1,3};
    cout<<slt.search(nums,1)<<endl;
    while(1);
}