#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> partition(string s) 
    {
    	vector<string> partition;
    	vector<vector<string> > result;

    	findNextPalindrome(s.begin(), s.end(), partition, result);
    	return result;
    }

	void findNextPalindrome(string::iterator begin, string::iterator end, vector<string> &partition, vector<vector<string> >& result)
	{
		if(begin == end) result.push_back(partition);
		string::iterator tail = begin + 1;
		while(tail<=end)
		{
			if(isPalindrome(begin,tail))
			{

				// cout<<"Palinrome found: "<< string(begin,end)<<endl;
				partition.push_back(string(begin,tail));
				findNextPalindrome(tail,end,partition,result);
				partition.pop_back();
			}
			++tail;
		}
	}

	bool isPalindrome(string::iterator begin, string::iterator end)
	{
		auto head = begin;
		auto tail = end -1;
		while(head<=tail)
		{

			if (*(head++)!=*(tail--)) return false;
		}
		return true;
	}
};

int main(void)
{
	Solution slt;
	string s;
	vector<vector<string>> res;
	while(cin>>s)
	{
		res = slt.partition(s);
		for(auto &v : res)
		{
			for(auto s : v)
			{
				cout<<s<<"\t";
			}
			cout<<endl;
		}
	}
}