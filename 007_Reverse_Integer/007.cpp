#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

int GetLastDigit(int & val)
{
	int a=0;

	if (0==val) 
	{
		return 0;
	}
	else
	{
		a= val%10;
		val=val/10;
		return a;
	}
}

    int reverse(int x) 
    {    	
    	int tmp;
    	int flag;    	
    	vector <int> digits;
    	
    	if (0==x) return 0 ;

    	if (x<0) 
    	{
    		flag = 1;
    		tmp = -x;
    	}
    	else
    	{
    		flag =0;
    		tmp = x;
    	}

    	while(0!=tmp)
    	{
    		digits.push_back(GetLastDigit(tmp));
    	}

    	int len =digits.size();
    	for(auto iter=digits.begin(); iter<digits.end(); ++iter)
    	{
    		tmp+=pow(10,len-1-(iter-digits.begin()))*(*iter);
    	}
    	if (tmp<0) tmp=0;

    	return flag? -tmp:tmp;
    }

    int main()
    {
    	int a ;
    	while (cin>>a)
    	{
    		cout<<reverse(a)<<endl;
    	}
    }