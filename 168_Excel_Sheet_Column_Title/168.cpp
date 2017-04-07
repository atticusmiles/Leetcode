#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) 
    {
    	string s;
    	int tmp = n;
    	do
    	{
    		s=char((--tmp)%26+'A')+s;
    		tmp = tmp/26;
    	}while(tmp);

   // 	if(s.size()>1) s.front()-=1;
    	return s;
    }
};

int main()
{
	Solution slt;
	int i;
	// while(cin>>i)
	// {
	// 	cout<<slt.convertToTitle(i)<<endl;
	// }
	for (i=1; i<1000; ++i)
	{
		cout<<i<<"."<<slt.convertToTitle(i)<<"\t"<<flush;
	}
	while(cin>>i	);
}