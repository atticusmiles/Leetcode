#include <iostream>
#include <vector>
#include <string>
using namespace std;

// class Solution {
// public:
//     string longestPalindrome(string s) 
//     {
//     	vector<pair<int,int>> psubstrs; 
//     	if(s.size()==0 || s.size()==1) return s;
    	
//     	for(int i=0; i<s.size()-1; ++i)
//     	{
//     		if(s[i]==s[i+1]) psubstrs.push_back(pair<int,int>(i,i+1));
//     	}

//     	for(int i=0; i<s.size()-2; ++i)
//     	{
//     		if(s[i]==s[i+2]) psubstrs.push_back(pair<int,int>(i,i+2));
//     	}

//     	if (psubstrs.empty()) return s.substr(0,1);

//     	pair<int,int> max_len(0,0);
//     	while(psubstrs.size())
//     	{
//     		for(auto p=psubstrs.begin(); p<psubstrs.end(); ++p)
//     		{
//     			if (p->first<=0 || p->second>=s.size()-1 || s[p->first-1]!=s[p->second+1])
//     			{
//     				if (p->second-p->first>max_len.second-max_len.first) max_len = *p;
//     				psubstrs.erase(p);
//     			}
//     			else
//     			{
//     				--(p->first);
//     				++(p->second);
//     			}
//     		}
//     	}
//     	return s.substr(max_len.first,(max_len.second - max_len.first +1));

//     }
// };

// class Solution{
// public:
// 	string longestPalindrome(string s)
// 	{
// 	    int size=s.size(),i;
// 	    char *t=new char[2*size+2],*q=t;
// 	    int *p=new int[2*size+1],mx=0,id=0,MAX=0,center=0;
// 	    for(*q='#',i=0;i<size;++i,*++q='#')*++q=s[i];

// 	    for(*++q=0,p[0]=i=1;t[i];i++) 
// 	    {
// 	        p[i]=mx>i?min(p[2*id-i],mx-i):1;
// 	        while(i+p[i]<=2*size+1 && t[i+p[i]]==t[i-p[i]])p[i]++;
// 	        if(i+p[i]>mx)mx=i+p[i],id=i;
// 	        if(p[i]>MAX)MAX=p[i],center=i;
// 	    }
// 	    delete(p),delete(t);
// 	    return s.substr((center-MAX+1)/2,MAX-1);
// 	}
// };

class Solution{
public:
	string longestPalindrome(string s) {
	    if (s.empty()) return "";
	    if (s.size() == 1) return s;

	    int min_start = 0, max_len = 1;

	    // for (int i = 0; i < s.size();) 
	    int i = 0;
	   	while(i<s.size())
	    {
	      if (s.size() - i <= max_len / 2) break;//the length remaining is not long enough to overtake current solution.
	      
	      int j = i, k = i;
	      
	      while (k < s.size()-1 && s[k+1] == s[k]) ++k; // Skip duplicate characters.
	      i = k+1;
	      while (k < s.size()-1 && j > 0 && s[k + 1] == s[j - 1]) { ++k; --j; } // Expand.
	      int new_len = k - j + 1;
	      if (new_len > max_len) { min_start = j; max_len = new_len; }
	    }
	    return s.substr(min_start, max_len);
	}
};


int main()
{
	Solution slt;
	string s;
	while(cin>>s)
	{
		cout<<slt.longestPalindrome(s)<<endl;
	}

}