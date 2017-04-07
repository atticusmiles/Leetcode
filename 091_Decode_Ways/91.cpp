#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) 
    {
        if(""==s) return 0;
        int ways_before =0;
        char last_char = '0';
        int ways = 1;
        for(auto c : s)
        {
            if(last_char<='2' && last_char>='1' )
            {
                if((last_char =='1'&&c>='1' && c<='9') || (last_char=='2' && c>='1' && c<='6'))
                {
                    ways = ways_before + ways;
                    ways_before = ways - ways_before;
                }
                else if ('0'==c)
                {
                    ways = ways_before;
                }
                
            }
            else 
            {
                if('0'==c) return 0;
                ways_before = ways;
            }
            last_char = c;
        }
        return ways;
    }
};

int main()
{
	Solution slt;
	string s;
	while(cin>>s)
	{
		cout<<slt.numDecodings(s)<<endl;
	}
}