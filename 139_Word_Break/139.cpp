#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) 
    {
    	if(s.size()==0 || wordDict.size()==0) return false;
    	if(1==s.size()) return (wordDict.find(s)!=wordDict.end());

    	vector<string::iterator> reachable{s.begin()-1};
    	for(auto iter = s.begin(); iter<s.end(); ++iter)
    	{
    		for(auto iHead = reachable.rbegin(); iHead<reachable.rend(); ++iHead)
    		{
    			if(wordDict.find(string((*iHead)+1,iter+1))!=wordDict.end())
    			{
    				reachable.push_back(iter);
    				break;
    			}
    		}
    	}
    	return (reachable.back()==s.end()-1);
    }
};