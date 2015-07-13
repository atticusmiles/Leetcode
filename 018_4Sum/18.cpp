#include <iostream>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>
#include <sstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) 
    {
    	unordered_map< int,vector<pair<pair<int,int>,pair<int,int>>>> data;
    	set<int> sums;
    	set<vector<int>> result;
    	//establish hash table
    	for(int i=0; i<nums.size(); ++i)
    	{
    		for(int j=i+1; j<nums.size(); ++j)
    		{
    			int numi=nums[i];
    			int numj=nums[j];
    			pair<int,int> num1(numi,i);
    			pair<int,int> num2(numj,j);
    			pair<pair<int,int>,pair<int,int>> sum(num1,num2);
    			sums.insert(numi+numj);
    			data[numi+numj].push_back(sum);
    		}
    	}

    	for(auto c: sums)
    	{
    		if(sums.find(target-c)!=sums.end())
    		{
    			for(auto iter1= data[c].begin(); iter1<data[c].end(); ++iter1)
    			{
    				for(auto iter2=data[target-c].begin(); iter2<data[target-c].end(); ++iter2)
    				{
						if(iter1->first!=iter2->first && iter1->first!=iter2->second && iter1->second!=iter2->first && iter1->second!=iter2->second)
						{
							vector<int> solution{iter1->first.first, iter1->second.first, iter2->first.first, iter2->second.first};
							sort(solution.begin(),solution.end());
							result.insert(solution);
						}
    				}
    			}
    		}
    	}
		vector<vector<int>> res(result.begin(),result.end());
		return res;
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
		vector<vector<int>> result = slt.fourSum(nums,target);
		for(auto &v:result)
		{
			for(auto &i: v)
			{
				cout<<i<<"\t";
			}
			cout<<endl;
		}
	}
}