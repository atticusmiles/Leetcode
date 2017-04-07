#include <unordered_set>
#include <string>
#include <iostream>
#include <sstream>
using namespace std;

class Solution {
public:
    bool isHappy(int n) 
    {
    	unordered_set<int> been_there;
    	int tmp=n;
    	while(1)
    	{
    		if(1==tmp)
    		{
    			return 1;
    		}
    		else
    		{
    			if(!been_there.insert(tmp).second) return false;
    		}
    		tmp=happyTransform(tmp);
    	}


    }
    int happyTransform(int n)
    {
    	string s;
    	stringstream ss;
    	ss<<n;
    	s=ss.str();

    	int result=0;
    	for(auto c:s)
    	{
    		result+=(c-'0')*(c-'0');
    	}
    	return result;
    }
};


int main()
{
	Solution slt;
	int val;
	while(cin>>val)
	{
		cout<<slt.happyTransform(val)<<endl;
	}
}