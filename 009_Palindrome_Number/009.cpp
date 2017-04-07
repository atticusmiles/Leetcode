#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
    {
        long long reverse=0;
        int tmp = x;

        if (x<0) return false;

        while(0!=tmp)
        {
        	reverse*=10;
        	reverse+=tmp%10;
        	tmp/=10;
        }

        return reverse==x;
    }
};

int main()
{
	Solution solution;
	int val;
	while(1)
	{
		cin>>val;
		cout<<solution.isPalindrome(val)<<endl;
	}
}