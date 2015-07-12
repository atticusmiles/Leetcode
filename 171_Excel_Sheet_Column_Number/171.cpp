#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) 
    {
    	int num=0;
    	for (auto iter=s.begin(); iter<s.end(); ++iter)
    	{
    		num=26*num+(*iter-'A'+1);
    	}
    	return num;
    }
};

int main()
{
	Solution slt;
	string s;
	while(cin>>s)
	{
		cout<<slt.titleToNumber(s)<<endl;
	}
}