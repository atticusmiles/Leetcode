#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) 
    {
    	vector <char> match_list;
    	for (char & c : s)
    	{
    		if ('{'==c || '['==c || '('==c)
    		{
    			match_list.push_back(c);
    		}
    		else
    		{
                if (match_list.empty()) return false;

                char last = match_list.back();

    			if ((('{'==last)&&('}'==c)) || (('['==last)&&(']'==c)) || (('('==last)&&(')'==c)))
    			{
    			//	cout<<"match";
    				match_list.pop_back();
    			}
    			else
    			{
    				// cout<<"last: "<<(char)(*(match_list.end()-1)-1)<<endl;
    				// cout<<"current: "<<c<<endl;
    				match_list.push_back(c);
    			//	cout<<"no match"<<endl;
    			}
    		}
    	}
    	return match_list.empty();
    }
};

int main()
{
	string s;
	Solution solution;
	while(cin>>s)
	{
		cout<<solution.isValid(s)<<endl;
	}
}