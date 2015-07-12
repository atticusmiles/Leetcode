#include <stdlib.h>
#include <iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) 
    {
    	uint32_t num=n;
    	int count=0;
    	uint32_t tmp;
        while(num)
        {	
			tmp=((~num)+1)&num;
        	num-=tmp;
        	++count;
        }
        return count;
    }
};

int main()
{
	Solution slt;
	uint32_t num;
	while(cin>>num)
	{
		// num=0x000000ff;
		cout<<hex<<num<<"\t";
		cout<<slt.hammingWeight(num)<<endl;
	}
}