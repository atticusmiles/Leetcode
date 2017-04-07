#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) 
    {
    	int height = matrix.size();
    	int width = matrix.front().size();

    	for(int i=0; i<height; ++i)
    	{
    		for(int j=0; j<width; ++j)
    		{
    			if(matrix[i][j]==0) 
    			{
    				matrix[i][0]=0;
    				matrix[0][j]=0;
    				
    				for( auto &v : matrix)
					{
						for(auto i : v)
						{
							cout<<i<<"\t";
						}
						cout<<endl;
					}
					cout<<endl;
    			}
    		}
    	}

    	for(int i=height-1; i>=0; --i)
    	{
    		for(int j=width-1; j>=0; --j)
    		{
    			if(matrix[0][j]==0 || matrix[i][0] ==0) 
    			{    				
    				matrix[i][j]=0;
    			}
    		}
    	}
    }
};

int main()
{
	vector<int> line0{0,0,0,5};
	vector<int> line1{4,3,1,4};
	vector<int> line2{0,1,1,4};
	vector<int> line3{1,2,1,3};
	vector<int> line4{0,0,1,1};
	vector<vector<int>> matrix{line0,line1,line2,line3,line4};
	Solution slt;
	slt.setZeroes(matrix);
	for( auto &v : matrix)
	{
		for(auto i : v)
		{
			cout<<i<<"\t";
		}
		cout<<endl;
	}
	while(1);
}