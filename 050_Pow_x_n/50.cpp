#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) 
    {
    	if(!n) return 1;

    	double seed = x;
    	long long progress = n;
    	progress = abs(progress);

    	double res = 1;
    	
    	while(progress)
    	{
    		if( 1 & progress) 
    		{
    			res *= seed;
    		}
    		seed*=seed;
    		progress>>=1;
    	}

    	res = (n<0)? 1/res : res;
    	return res;
    }
};

int main()
{
	double x;
	int n;
	Solution slt;
	while(cin>>x>>n)
	{
		// cout<<hex<<int(-2147483648)<<endl;
		cout<<slt.myPow(x, n)<<endl;
	}
}