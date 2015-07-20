#include <iostream>
using namespace std;

class Solution {
public:
    int countDigitOne(int n) 
    {
    	if(0==n) return 0;
    	int last_digit = n%10;
    	int times = n/10;
    	
    	
    }
};

int main()
{
	int n;
	Solution slt;
	while(cin>>n)
	{
		cout<<slt.countDigitOne(n)<<endl;
	}
}