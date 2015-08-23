#include <unordered_set>
#include <string>
#include <vector>
using namespace std;

class treenode 
{
public:
	treenode(string::iterator init_iter):iter(init_iter){}
	string::iterator iter;
	vector<treenode*> childs;
};


class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) 
    {
    	if(s.size()==0 || wordDict.size()==0) return vector<string>();

    	vector<treenode> reachable{treenode(s.begin()-1)};
    	
    	for(auto iter = s.begin(); iter<s.end(); ++iter)
    	{
    		bool inserted = false;
    		for(auto iHead = reachable.rbegin(); iHead<reachable.rend(); ++iHead)
    		{
    			if(wordDict.find(string((iHead->iter)+1,iter+1))!=wordDict.end())
    			{
    				if(!inserted)
    				{
    					reachable.push_back(treenode(iter));
    					inserted = true;
    				}
    				iHead->childs.push_back(&reachable.back());
    			}
    		}
    	}
    	vector<treenode*> path;
    	vector<string> res;
    	getPath(&reachable.front(),s.end()-1,path,res);
    	return res;
    }

    void getPath(treenode* root, string::iterator last_char, vector<treenode*>& path ,vector<string>& result)
    {
    	path.push_back(root);
    	if(root->childs.size()==0)
    	{
    		if(root->iter == last_char)
    		{
    			string ans;
	    		for(int i=0; i<path.size()-1; ++i)
	    		{
	    			ans.append(string((path[i]->iter+1),path[i+1]->iter));
	    			ans.append(" ");
	    			result.push_back(ans);
	    		}
    		}
    	}
    	else
    	{
    		for(auto ptrChild : root->childs )
    		{
    			getPath(ptrChild, last_char, path, result);
    		}
    	}
    	path.pop_back();
    }
};
