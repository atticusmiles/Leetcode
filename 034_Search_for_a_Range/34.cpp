#include <sstream>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) 
    {
    	int position = binarySearch(nums,target);
    	if (-1==position) return vector<int>{-1,-1};
    	int head = position;
    	int rear = position;
    	while(nums[head-1]==target && head>0) --head;
    	while(nums[rear+1]==target && rear<nums.size()-1) ++rear;
    	return vector<int> {head,rear};
    }

    int binarySearch(vector<int> &nums, int target)
    {
    	int head = 0;
    	int rear = nums.size()-1;

    	while(head<=rear)
    	{
    		int pivot = (head+rear)/2;
    		if(nums[pivot]<target) 
    		{
    			head = pivot +1;
    		}
    		else if(nums[pivot]>target)
    		{
    			rear = pivot-1;
    		}
    		else
    		{
    			return pivot;
    		}
    	}
    	return -1;
    }
};

int main()
{
	Solution slt;
	vector<int> data;
	string s;

	while(getline(cin,s))
	{
		int val;
		stringstream ss(s);
		while(ss>>val) data.push_back(val);
		cout<<"val:";
		cin>>val;
		vector<int> res = slt.searchRange(data, val);
		cout<<res.front()<<","<<res.back()<<endl;
		data.clear();
		cin.get();
	}
}