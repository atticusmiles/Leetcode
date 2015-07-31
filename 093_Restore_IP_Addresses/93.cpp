#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) 
    {
    	string src = s;
    	vector<string> result;
    	vector<string> IP;
    	auto end_iter = src.end();
    	auto progress_iter = src.begin();
    	findIP(end_iter,progress_iter,IP,4,result);
    	return result;
    }

    void findIP (string::iterator &end, string::iterator current, vector<string> &IP_combination, int slot, vector<string> &result)
    {
    	string snum;
    	auto siter = current;
    	int num;
    	for(int i=1; i<=3; ++i)
    	{
    		if(end==siter) break;
    		snum+=*siter++;
    		if(slot==1 && (end!=siter)) continue;
    		num = stoi(snum);
    		if('0'==snum.front() && snum.size()>1) break;
    		if(num<256)
    		{
    			IP_combination.push_back(snum);
    			// for(auto ip:IP_combination) cout<<ip<<"\t";
    			// cout<<endl;
    			if(1==slot) 
    			{

    				// cout<<"found"<<endl;
    				string res;
    				for(auto s:IP_combination)
    				{
    					res+=s;
    					res+=".";
    				}
    				res.pop_back();
    				result.push_back(res);
    			}
    			else
    			{
    				findIP(end,siter,IP_combination,slot-1,result);
    			}
    			IP_combination.pop_back();
    		}
    	}
    }
};


int main()
{
	vector<string> res;
	Solution slt;
	string s;
	while(cin>>s)
	{
		res = slt.restoreIpAddresses(s);
		for(auto ip:res)
		{
			cout<<ip<<endl;
		}
		cout<<"done"<<endl;
	}
}