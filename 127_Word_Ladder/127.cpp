
#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) 
    {
    	int min_step = 0;
    	string dst = endWord;
    	vector<string>dict(wordDict.begin(),wordDict.end());
    	findNextStep(beginWord, dst, dict, 2, min_step);
    	return min_step;

    }

    void findNextStep(string src, string &dst, vector<string>& dict, int step, int &min_step)
    {
    	cout<<"src: "<<src<<" step: "<<step<<endl;
        if(0!=min_step && step>=min_step) return;
    	if(isNextStep(src,dst))
    	{
    		// cout<<"found a way"<<endl;
    		min_step = (min_step==0 || min_step>step)? step : min_step;
    		return;
    	}
    	for(auto &s: dict)
    	{
    		if(s!= "" && isNextStep(src,s))
    		{
    			string tmp = "";
    			swap(s,tmp);
    			findNextStep(tmp, dst, dict, step+1, min_step);
    			swap(s,tmp);
    		}
    	}

    }

private:
    bool isNextStep(string src, string dst)
    {
    	int count_diff=0;

    	if(src.size()!= dst.size()) return false;
    	for(int i=0; i< src.size(); ++i)
    	{
    		if(src[i]!=dst[i]) count_diff+=1;
    		if(count_diff>=2) return false;
    	}
    	if (1 == count_diff) return true;
    	else return false;
    }
};

int main()
{
	Solution slt;
	// unordered_set<string> dict{"hot","cog","dog","tot","hog","hop","pot","dot"};
	unordered_set<string> dict{"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm","le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo","ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur","rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th","pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa","pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne","mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa","he","lr","sq","ye"};
	// unordered_set<string> dict{"hot","dog","dot"};
	cout<<slt.ladderLength("qa", "sq", dict)<<endl;

	while(1);
}