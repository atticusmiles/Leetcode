#include <iostream>
#include <unordered_map>
#include <set>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> anagrams(vector<string>& strs) 
    {
        vector<string> res;
        unordered_map<string,string> data;
        for(auto s: strs)
        {
            string fingerprint = get_fingerprint(s);
            // cout<<"fingerprint of\t"<<s<<"\tis\t"<<fingerprint<<endl;
            auto insert_res = data.insert({fingerprint,s});
            if(!(insert_res.second))
            {
                string &tmp = insert_res.first->second;
                if(tmp != "\t")
                {
                    res.push_back(tmp);
                    res.push_back(s);
                    tmp = "\t";
                } 
                else
                {
                    res.push_back(s);
                }
            }
        }
        return res;
    }


    string get_fingerprint(string s)
    {
    	string fingerprint(256,0);
    	
    	for(auto c : s )
    	{
            ++fingerprint[c];
    	}
        return fingerprint;
    }
};

int main()
{
    Solution slt;
    vector<string> strs{"","ba"};
    vector<string> res = slt.anagrams(strs);
    for(int i = 0; i<res.size(); ++i)
    {
        cout<<i<<":\t"<<res[i]<<endl;
    }
    while(1);
}