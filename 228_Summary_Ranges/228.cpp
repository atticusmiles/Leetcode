#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
    	vector<string> summary;

		vector<int>::iterator iter= nums.begin();
    	while(iter!=nums.end())
    	{
    		string range;
    		stringstream ss;

    		int flag=0;
    		ss<<*iter;
    		while(nums.end()!=iter+1 && *iter==(*(iter+1)-1))
    		{
    			++iter;
    			flag=1;
    		}
    		if(flag) ss<<"->"<<*iter;
    		range = ss.str();
    		summary.push_back(range);
    		++iter;
    	}
    	return summary;
    }
};

int main()
{
	Solution slt;
	vector<int> nums{1,2,3,5,6,7,9};
	vector<string> summary= slt.summaryRanges(nums);
	for(auto s:summary)
	{
		cout<<s<<endl;
	}
	while(1);
}
