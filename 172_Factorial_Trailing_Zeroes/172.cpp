#include <iostream>
using namespace std;
//v0.1
// class Solution {
// public:
//     int trailingZeroes(int n) 
//     {
//     	int num=1;
//     	int count=0;
//     	for(int i=1; i<=n; ++i)
//     	{

//     		num*=i;
//     		while(0==num%10)
//     		{
//     			num/=10;
//     			count+=1;
//     		}
//     		cout<<"core"<<i<<"\t"<<num<<endl;
//     	}
//     	return count;
//     }
// };
//v0.2
// class Solution {
// public:
//     int trailingZeroes(int n) 
//     {
//     	int factor_2=0;
//     	int factor_5=0;
//     	int zero=0;
//     	for(int i=1; i<=n; ++i)
//     	{
//     		int tmp=i;
//     		while(tmp%2==0 /*&& 0!=tmp*/)
//     		{
//     			tmp/=2;
//     			++factor_2;
//     		}
//     		while(tmp%5==0 /*&& 0!=tmp*/)
//     		{
//     			tmp/=5;
//     			++factor_5;
//     		}
//     		int tmp_min=min(factor_2,factor_5);
//     		zero+=tmp_min;
//     		factor_5-=tmp_min;
//     		factor_2-=tmp_min;
//     	}

//     	return zero;
//     }
// };
// 
class Solution {
public:
    int trailingZeroes(int n) { 
        int count = 0;
        for (long long i = 5; n / i; i *= 5)
            count += n / i;
        return count;
    }
};

int main()
{
	Solution slt;
	int num;
	// cout<<"0\%2="<<0%2<<"\t";
	while(cin>>num)
	{
	//	int res =1;
		cout<<slt.trailingZeroes(num)<<"\n";
		// for (int i=1; i<=num; ++i)
		// {1808548329
		// 	res*=i;
		// }
		// cout<<res<<endl;
	}
}