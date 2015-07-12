#include <vector>
#include <unordered_map>
#include <set>
#include <iostream>
using namespace std;

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) 
    {
    	if(nums.empty()) return false;
    	int len = (k+1<nums.size())? k+1 : nums.size();
		set<int> data(nums.begin(),nums.begin()+len);
        cout<<data.size()<<endl;
    	for(int i=0; i+len-1<nums.size(); ++i)
    	{
    		if(data.size()<len) return true;
    		data.erase(nums[i]);
    		data.insert(nums[i+len]);
    	}
    	return false;
    }
};

int main()
{
	Solution slt;
	vector<int> nums{1};
	int k=1;
	cout<<slt.containsNearbyDuplicate(nums, k)<<endl;
	while(1);
}