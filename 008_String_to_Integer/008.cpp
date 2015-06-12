#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int myAtoi(string str) 
    {
    	auto iter = str.begin();
    	bool flag;

    	if (0==str.size()) return 0;
      //skip spaces
   		while(' '==*iter)
   		{
   			++iter;
   		}
      //get sig if there is one 
   		if ('+'==*iter || '-'==*iter)
   		{
   			flag = ('-'==*iter);
   			++iter;
   		}
      //check first valid char 
   		if (*iter>'9'|| *iter <'0') return 0;

   		vector <char> digits;

      //skip zeros
   		while (0==*iter) ++iter;
      //get all the digits
   		while (*iter>='0' && *iter <='9')
   		{
   			digits.push_back(*iter);
   			++iter;
   		}

   		if (digits.size()>10)
   		{
   			return flag ? INT_MIN:INT_MAX;
   		}

      int len= digits.size();
      int tmp=0;

   		for(auto iterator=digits.begin(); iterator<digits.end(); ++iterator)
    	{
    		tmp+=pow(10,len-1-(iterator-digits.begin()))*(*iterator -'0');
    	}

      if(tmp<0)
      {
        return flag ? INT_MIN:INT_MAX;
      }
      else
      {
        return flag ? -tmp:tmp;
      }
    }
};

int main()
{
  string a;
  Solution slt;
  while(cin>>a)
  {
    cout<<slt.myAtoi(a)<<endl;
  }
}