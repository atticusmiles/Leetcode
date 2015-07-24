#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePaths(int m, int n) 
    {
    	vector<int> line(n,1);
    	
        for(int i=1; i<m; ++i)
        {
        	vector<int> next_line(n,1);
        	for(int k=1; k<n; ++k)
        	{
        		next_line[k]=next_line[k-1]+line[k];
        	}
        	line.swap(next_line);
        }
        return line.back();
    }
};

int main()
{
	Solution slt;
	int width,height;
	while(cin>>height>>width)
	{
		cout<<slt.uniquePaths(height, width)<<endl;
	}	

}