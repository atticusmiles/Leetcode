#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) 
    {
    	long long head = 0;
    	long long tail = x;
        // int cnt = 0;
    	while(head<=tail)
    	{
            // ++cnt;
    		long long tmp = (head+tail)/2;
            // cout<<head<<"\t"<<tmp<<"\t"<<tail<<endl;
    		if (tmp*tmp>x) tail = tmp - 1;
    		else if(tmp*tmp <x) head=tmp + 1;
    		else return tmp;
    	}
    	return tail;
    }
};

int main()
{
	Solution slt;
	int num;
	while(cin>>num)
	{
		// cout<<"Square root of "<<num<<" is "<<slt.mySqrt(num)<<endl;
        cout<<slt.mySqrt(num)<<endl;
	}
}
