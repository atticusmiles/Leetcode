#include <string>
#include <vector>
using namespace std;

class Solution 
{
public:
    string convert(string s, int numRows) 
    {
        vector <string> strs (numRows);

        for (auto iter = s.begin(); iter < s.end(); ++iter)
        {
        	int serial = iter - s.begin();
        	int row;

        	int position= 1==numRows ? 0 : serial%(2*numRows-2);

        	if (position<numRows)
        	{
        		row=position;
        	}
        	else
        	{
        		row=2*numRows-2-position;
        	}
        	strs[row].push_back(*iter);
       	}

       	string dst;
       	for (auto iter= strs.begin(); iter<strs.end(); ++iter)
       	{
       		dst+=*iter;
       	}

       	return dst;
    }
};