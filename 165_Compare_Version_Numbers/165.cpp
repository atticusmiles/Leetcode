#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
    	vector<int> v1 = get_version(version1);
    	vector<int> v2 = get_version(version2);

    	auto iter1=v1.begin();
    	auto iter2=v2.begin();
    	auto iter_over= (v1.size()>v2.size())? (v1.end()-(v1.size()-v2.size())):(v2.end()-(v2.size()-v1.size()));
    	auto iter_over_end = (v1.size()>v2.size())? (v1.end()):(v2.end());
    	while(iter1<v1.end() && iter2<v2.end())
    	{
    		if(*iter1>*iter2) return 1;
    		if(*iter1<*iter2) return -1;

    		++iter1;
    		++iter2;
    	}
    	if(v1.end()==iter1 && v2.end()==iter2) return 0;
    	else
    	{
    		for (;iter_over<iter_over_end;++iter_over)
    		{
    			if (*iter_over) return (v1.size()>v2.size())? 1:-1;
    		}
    		return 0;
    	}

    }
    //  int compareVersion(string version1, string version2) {
    //     const char *p1 = version1.c_str()-1;
    //     const char *p2 = version2.c_str()-1;
    //     do{
    //         int v1 = 0, v2 =0;
    //         if (p1){
    //             v1=atoi(p1+1);
    //             p1 = strchr(p1+1, '.');
    //         }
    //         if (p2){
    //             v2=atoi(p2+1);
    //             p2 = strchr(p2+1, '.');
    //         }
    //         if (v1<v2) return -1;
    //         if (v2<v1) return 1;
    //     }while(p1||p2);
    //     return 0;
    // }
    vector<int> get_version(string s)
    {
    	string num;
    	vector<int> version;
    	for(auto iter=s.begin(); iter<s.end(); ++iter)
    	{
    		if('.'==*iter)
    		{
    			version.push_back(stoi(num));
    			num.clear();
    		}
    		else
    		{
    			num+=*iter;
    		}
    	}
    	version.push_back(stoi(num));
    	return version;
    }
};

int main()
{
	Solution slt;
	string s1;
	string s2;
	while(cin>>s1>>s2)
	{
		cout<<slt.compareVersion(s1,s2)<<endl;
	}

}