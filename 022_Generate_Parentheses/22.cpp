#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) 
    {
    	vector<string> result;
    	if (n<=0) return result;
    	vector<pair<string,int>> current;
    	vector<pair<string,int>> next;
    	current.push_back(pair<string,int> ("",0));
    	// need to add 2n elements in the middle;
    	int len = 2*n;
    	for(int i=0; i<len; ++i)
    	{
    		for(auto c : current)
    		{
    			if(c.second<(len-i) && c.second>0)
    			{
    				next.push_back(pair<string,int> (c.first+"(",c.second+1));
    				next.push_back(pair<string,int> (c.first+")",c.second-1));
    			}
    			else
    			{
    				if(c.second<=0) next.push_back(pair<string,int> (c.first+"(",c.second+1));
    				else next.push_back(pair<string,int> (c.first+")",c.second-1));
    			}
    		}
    		current.swap(next);
    		next.clear();
    	}
    	for(auto p: current)
    	{
    		result.push_back(p.first);
    	}
    	return result;
    }
};

int main()
{
	int n;
	Solution slt;
	while(cin>>n)
	{
		vector<string> v= slt.generateParenthesis(n);
		for (auto s:v)
		{
			cout<<s<<"\t";
		}
		cout<<endl;
	}
}