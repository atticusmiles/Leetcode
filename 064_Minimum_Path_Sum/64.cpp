#include <iostream>
#include <vector>
using namespace std;

// class Solution {
// public:
//     int minPathSum(vector<vector<int>>& grid) 
//     {
//     	vector<vector<int>> res(grid.size(), vector<int>(grid.front().size(),-1));
//     	res[0][0] = grid[0][0];
// 		int result=getMinPathSum(grid,grid.front().size()-1,grid.size()-1,res);

// 		return result;
//     }
//     int getMinPathSum(vector<vector<int>> &grid, int x, int y,vector<vector<int>> &res)
//     {  
//     	if (x<0 || y<0 ) 
//     	{
// 			return INT_MAX;
//     	}
//     	if(res[y][x]!=-1) 
//     	{
//     		return res[y][x];
//     	}
//     	int this_res = min(getMinPathSum(grid,x-1,y,res),getMinPathSum(grid,x,y-1,res))+grid[y][x];
//     	res[y][x] = this_res;

//     	return this_res;
    	
//     }
// };

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        vector<int> line(grid.front().size(),INT_MAX);
        vector<int> next_line;
        line.front()=0;

        for(int i =0; i<grid.size(); ++i)
        {
            next_line.push_back(line.front()+grid[i][0]);
            for(int j = 1; j<grid.front().size(); ++j)
            {
                next_line.push_back(grid[i][j] + min(next_line[j-1],line[j]));
            }
            line.swap(next_line);
            next_line.clear();
        }
        return line.back();
    }  
};

int main()
{

	vector<int> line1{1,2};
	vector<int> line2{1,1};

	vector<vector<int>> grid{line1,line2};
	Solution slt;
	cout<<slt.minPathSum(grid)<<endl;
	while(1);
}