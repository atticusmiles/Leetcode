#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) 
    {
    	int flag = 1;
    	for (auto riter=digits.rbegin(); riter<digits.rend(); ++riter)
    	{
    		if(9==*riter)
    		{
    			*riter=0;
    		}
    		else
    		{
    			*riter+=1;
    			flag = 0;
    			break;
    		}
    	}
    	if (flag) digits.insert(digits.begin(),1);
    	return digits;
    }
};


int main()
{
	vector<int> digits={9,9,9,9,1,9,9,9,9,9,9,9,9,9};
	Solution slt;
	slt.plusOne(digits);
	for(auto c:digits)
	{
		cout<<c<<flush;
	}
	while(1);
}