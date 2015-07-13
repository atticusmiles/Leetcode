#include <sstream>
#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) 
    {
    	sort(nums.begin(),nums.end());

    	int close_range = nums[0]+nums[1]+nums[2]-target;

    	for(auto iter=nums.begin(); iter<nums.end(); ++iter  )
    	{
    		auto head = iter+1;
    		auto rear = nums.end() -1;
			while(head<rear)
			{
				int val= *iter+*head+*rear-target;
				if (abs(val)<abs(close_range)) close_range=val;

				if(*head+*rear+*iter<target) ++head;
				else if(*head+*rear+*iter>target) --rear;
				else return target;
			}
    	}
    	return target+close_range;
    }
};

int main()
{
	
	Solution slt;
	while(1)
	{
		string s;
		stringstream ss;
		cout<<"input vector:";
		getline(cin,s);
		cout<<"input done\n";
		vector<int> nums;
		int a;
		ss<<s;
		int target;
		cout<<"input target:";
		cin>>target;
		cout<<"input done\n";
		while(ss>>a) nums.push_back(a);
		cout<<slt.threeSumClosest(nums,target)<<endl;
		cin.get();
	}
}