#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) 
    {
    	vector<vector<int>> result;
        vector<int> combination;
        findCombination(0,n,0,k,combination,result);
        return result;
    }

    void findCombination(int start, int& max_num, int size, int& max_size, vector<int>& combination, vector<vector<int>> &result)
    {
    	if(max_size==size)
    	{
    		result.push_back(combination);
    	}
    	else
    	{
    		int top = (max_num-(max_size-size-1));
    		for(int i=start+1; i<= top; ++i)
			{
				combination.push_back(i);
				findCombination(i,max_num,size+1,max_size,combination,result);
				combination.pop_back();
			}
    	}
    }
};

int main()
{
	Solution slt;
	int n,k;
	while(cin>>n>>k)
	{
		vector<vector<int>> res = slt.combine(n,k);
		for(auto &v:res)
		{
			for(auto &i: v)
			{
				cout<<i<<"\t";
			}
			cout<<endl;
		}
	}
}