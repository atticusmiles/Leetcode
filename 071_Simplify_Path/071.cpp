#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) 
    {
    	auto iter = path.begin();
    	vector<string> s_path;
    	while(iter!=path.end())
    	{
    		string this_step = getNextStep(iter,path);
    		if(this_step=="/." or this_step=="/") continue;
            else if (this_step =="/..") 
            {
                if(s_path.size()!=0) s_path.pop_back();
            }
            else s_path.push_back(this_step);
    	}
        if(s_path.size()==0) return "/";
        else
        {
            string res;
            for(auto s:s_path)
                res+=s;
            return res;
        }
    }
    string getNextStep(string::iterator &iter ,string &path)
    {
    	string step;
    	step.push_back(*iter++);
    	while(*iter!='/' && iter!=path.end())
    	{
    		step.push_back(*iter++);
    	}
		return step;
    }
};

int main()
{
    Solution slt;
    string path;
    while(cin>>path)
    {
        cout<<slt.simplifyPath(path)<<endl;
    }
}