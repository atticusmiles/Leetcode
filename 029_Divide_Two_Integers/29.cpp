#include <iostream>
#include <stdlib.h>
using namespace std;


#define MAX_INT 0x7fffffff
class Solution {
public:
    int divide(int dividend, int divisor) 
    {
    	if (0==divisor) return MAX_INT;
        int sig = ((divisor<0 && dividend>0) || (dividend<0 && divisor >0))? 0 : 1;
        long long divisor_pos = divisor; 
        divisor_pos=abs(divisor_pos);
        long long dividend_pos = dividend; 
        dividend_pos=abs(dividend_pos);
        int slot = 32;
        long long sum =0;
        long long result =0;
        long long seed = 1;
        while(slot>=0)
        {
			long long sum_tmp = (divisor_pos<<slot)+sum;

			if(sum_tmp<=dividend_pos && sum_tmp>0)
			{
				sum = sum_tmp;
				result+= (seed<<slot);
			}
			 cout<<result<<endl;
			--slot;
        }
        result = (sig)? result:-result;
        if (result>MAX_INT) result = MAX_INT;
        return result;
    }
};

int main()
{
	int m,n;
	Solution slt;
	// cout<<"MAX_INT"<<MAX_INT;
	// cout<<(1<<31)<<endl;
	while(cin>>m>>n)
	{
		long long res = slt.divide(m, n);
		// cout<<res<<endl;
		cout<<m<<" / "<<n<<" = "<<res<<" while it should be "/*(m/n)*/<<endl;
	}
}