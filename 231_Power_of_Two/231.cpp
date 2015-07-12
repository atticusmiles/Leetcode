#include <iostream>
using namespace std;
class Solution {
public:
    bool isPowerOfTwo(int n) 
    {
    	return !(n&(n-1));   
    }
};

int main()
{
	int num;
	Solution slt;
	while(cin>>num)
	{
		cout<<slt.isPowerOfTwo(num)<<endl;
	}
}