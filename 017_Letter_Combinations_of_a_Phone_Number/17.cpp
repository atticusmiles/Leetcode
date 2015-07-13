#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) 
    {
    	vector<string> data{"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    	vector<string> result;
    	if(0==digits.size()) return result;
    	result.push_back("");
    	for(auto iter=digits.begin(); iter<digits.end(); ++iter)
    	{
    		int ori_len = result.size();
    		for(auto c:data[(*iter)-'0'])
    		{
    			for (int i=0; i<ori_len; ++i)
    			{
    				result.push_back(result[i]+c);
    			}
    		}
    		//注意,erase(first,last)中的last指的是要被删除的最后一个元素的下一个位置!!
    		result.erase(result.begin(), result.begin()+ori_len);
    	}
    	return result;
    }
};

int main()
{
	Solution slt;
	string s;
	while(cin>>s)
	{
		vector<string> result = slt.letterCombinations(s);	
		for(auto c:result)
		{
			cout<<c<<"\t";
		}
		cout<<endl;
	}
}