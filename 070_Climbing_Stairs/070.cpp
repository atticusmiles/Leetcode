#include <iostream>
using namespace std;

class Solution {
public:
    int climbStairs(int n) 
    {
    	if (1==n) return 1;
    	if (2==n) return 2;
		
		int t1 = 1;
		int t2 = 2;
		int tmp;

		for(int i=0; i<(n-2); ++i)
		{
			tmp = t1 +t2;
			t1 = t2;
			t2 = tmp; 
		}
		return t2;
    }
};

int main()
{
	Solution slt;
	int i;
	// while(cin>>i)
	// {
	// 	cout<<slt.climbStairs(i)<<endl;
	// }
	for (i = 1; i<46 ; ++i)
	{
		cout<<slt.climbStairs(i)<<"\t"<<flush;
	}
	while(1);
	return 1;
}