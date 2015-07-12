#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

// int lengthOfLongestSubstring(string s) {
//     if(s.empty())
//     {
//         return 0;
//     }

//     int maxLen = 0;
//     int start = 0;
//     vector<int> registry;
//     registry.resize(256, -1); // char can be the index here
//     int j = start;
//     while(j < s.length())
//     {
//         if(registry[s[j]] != -1)
//         {
//             maxLen = max(maxLen, j - start);
//             // clean up the registry up to the previous occurence of the current char, inclusively
//             for(int k = start; k < registry[s[j]]; ++k)
//             {
//                 registry[s[k]] = -1;
//             }
//             start = registry[s[j]] + 1;                
//         }
//         registry[s[j]] = j;
//         ++j;
//     }
//     return max(maxLen, j - start);
// // }

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
    	vector<int> cache(256,-1);
    	int head = 0;
    	int tail = 0;
    	int max_len=0;

    	while(s.end()!=s.begin()+tail)
    	{
			if(cache[s[tail]]!=-1)
			{
				// cout<<s[tail]<<"-"<<pos->second;
				if(cache[s[tail]]>=head)
				{
					head=(cache[s[tail]])+1;
				}
				// cout<<"head:"<<head<<endl;
			}

			cache[s[tail]]=tail;
			++tail;
			int len = tail - head;
			// if(len>max_len) cout<<"head:"<<head<<"tail:"<<tail<<endl;
			max_len = (len>max_len)? len:max_len;

    	}
    	return max_len;
    }
};

int main()
{
	Solution slt;
	string s;
	while(cin>>s)
	{
		cout<<slt.lengthOfLongestSubstring(s)<<endl;
	}
}