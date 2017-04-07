#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
    	int width = matrix.size();
    	int core = (width-1)/2;
    	for (int i = 0; i<=core; ++i)
    	{
    		int x1,x2,x3,x4;
    		int y1,y2,y3,y4;
    		for(int j = i; j <=width-i-2; ++j)
    		{
    			x1 = j;			y1 = i;
    			x2 = width - y1 -1;  y2= x1;
    			x3 = width - x1 -1;  y3= width - y1 - 1;
    			x4 = y1; 		y4 = width - 1 - x1;
    			int tmp = 0;
    			swap(matrix[y1][x1],tmp);
    			swap(matrix[y2][x2],tmp);
    			swap(matrix[y3][x3],tmp);
    			swap(matrix[y4][x4],tmp);
    			swap(matrix[y1][x1],tmp);
    		}
    	}    
    }
};