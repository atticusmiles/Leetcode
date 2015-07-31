#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
    	int height = obstacleGrid.size();
    	int width = obstacleGrid.front().size();
    	vector<int> line(width,0);
    	for(int i =0; i< width; ++i)
    	{
    		if(0==obstacleGrid.front()[i]) line[i]=1;
    		else break; 
    	}
    	for(int i:line) cout<<i<<"\t";
    	cout<<endl;
    	int v_flag = (obstacleGrid[0][0])? 0 : 1;
    	for(int i=1; i<height; ++i)
    	{
    		vector<int> next_line(width,0);
    		if(0==obstacleGrid[i][0] && v_flag==1) next_line.front()=1;
    		else v_flag=0;

    		for(int j=1; j<width; ++j)
    		{
    			if(obstacleGrid[i][j]) next_line[j]=0;
    			else
    			{
    				next_line[j]=next_line[j-1]+line[j];
    			}
    		}
    		line.swap(next_line);
    	}
    	return line.back();
    }
};

int main()
{
	vector<int> line0{1};
	vector<int> line1{0};
	vector<vector<int>> data{line0,line1};
	Solution slt;
	cout<<slt.uniquePathsWithObstacles(data)<<endl;
	while(1);
}