#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) 
    {
    	auto aiter= a.rbegin();
    	auto biter= b.rbegin();
    	string s;

        int flag = 0;

   		while(1)
   		{
   			int digit = 0;

            digit+= (a.rend()==aiter)? 0 : (*(aiter++)-'0');
            digit+= (b.rend()==biter)? 0 : (*(biter++)-'0');
            digit+= flag;

            switch(digit)
            {
                case 0:     s="0"+s;    flag=0;     break;
                case 1:     s="1"+s;    flag=0;     break;
                case 2:     s="0"+s;    flag=1;     break;
                case 3:     s="1"+s;    flag=1;     break;
            }

            if (a.rend()==aiter && b.rend()==biter) break;
   		}
        if (flag) s="1"+s;
        return s;
    }
};

int main()
{
    string s1;
    string s2;
    Solution slt;
    while(1)
    {
        cin>>s1>>s2;
        cout<<slt.addBinary(s1, s2)<<endl;
    }
    return 1;
}