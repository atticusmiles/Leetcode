#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
	void reverseWords(string &s) 
	{
		reverse(s.begin(), s.end());
		// cout<<s<<endl;
		auto iter_head = s.begin();
		auto iter_tail = s.begin();

		while(iter_head != s.end())
		{
			if(iter_tail != s.end() && *iter_tail != ' ')
			{
				++iter_tail;
			}
			else
			{
				if(iter_tail==iter_head)
				{
					s.erase(iter_head);
				}
				else
				{
					reverse(iter_head, iter_tail);

					if(iter_tail==s.end())
					{
						iter_head = iter_tail;	
					}
					else
					{
						iter_head = iter_tail+1;
						iter_tail = iter_head;
					}
				}
			}
		}
		if(s.back()==' ')
		{
			s.erase(s.end()-1);
		}
	}
};


int main()
{
	Solution slt;
	string s;
	while(cin>>s)
	{
		s = "1";
		slt.reverseWords(s);
		cout<<s<<endl;
	}
}