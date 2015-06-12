#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) 
    {         
      string min_len_str;

        if (0==strs.size())
        {
            return min_len_str;
        }

    	int min_len= strs[0].length();

    	//find the shortest string in the vector
   		for (auto iter =strs.begin(); iter< strs.end(); ++iter)
   		{
   			if ((*iter).length()<=min_len)
   			{
   				min_len = (*iter).length();
   				min_len_str = *iter;
   			}
   		}

   		string tmp;
   		for (int i=0; i<=min_len; ++i )
   		{
   			tmp = min_len_str.substr(0,i);
            for (auto iter =strs.begin(); iter< strs.end(); ++iter)
            {
                if (0!=iter->find(tmp))
                {
                    return min_len_str.substr(0,i-1);
                }
            }
   		}

        return min_len_str;
    }
};