#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) 
    {
    	//steps
    	if(1==n) return "1";

    	vector<int> step{1,1};
    	for(int i=2; i<n; ++i)
    	{
    		step.push_back(step.back()*i);
    	}
    	// cout<<"step:\n";
    	// for(int i:step) cout<<i<<"\t"<<endl;

    	vector<int> seq;
    	int tmp = k - 1;
    	int pos = step.size()-1;

    	while(pos>=0)
    	{
    		seq.push_back(tmp/step[pos]);
    		tmp=tmp%step[pos];
    		--pos;
    	} 

    	// cout<<"seq:\n";
    	// for(int i:seq) cout<<i<<"\t"<<endl;

    	string src;
    	// cout<<"src:\n";
    	for(int i =1; i<=n; ++i)
    	{
    		src.push_back(i+'0');
    		// cout<<src<<endl;
    	}
    	string dst;
    	// cout<<"dst:\n";
    	for(int c:seq)
    	{
    		dst.push_back(src[c]);
    		src.erase(src.begin()+c);
    	}
    	return dst;
    }

};

int main()
{
	int n,k;
	Solution slt;
	while(cin>>n>>k)
	{
		cout<<slt.getPermutation(n,k)<<endl;
	}
}