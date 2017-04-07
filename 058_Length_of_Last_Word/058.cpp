#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) 
    {
    	int len=0;
    	int flag=0;
        for(auto riter=s.rbegin(); riter<s.rend(); ++riter)
        {
        	if (' '!=*riter)
        	{
        		flag=1;
        		++len;
        	}
        	else
        	{
        		if (1==flag)
        		{
        			return len;
        		}
        	}
        }
        return len;
    }
};

int main()
{
	Solution slt;
	string s;
	while(getline(cin,s))
	{
		cout<<slt.lengthOfLastWord(s)<<endl;
	}
}