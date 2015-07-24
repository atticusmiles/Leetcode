#include <vector>
using namespace std;

class CPoint
{
	public:
	/* data */
	int x = 0;
	int y = 0;
	CPoint() =default;
	CPoint(int a,int b)
	{
		x= a;
		y= b;
	}
	bool operator ==(CPoint target)
	{
		return (x==target.x)&&(y==target.y);
	}
};


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
    	vector<int> res;
    	int height = matrix.size() - 1;
    	if(height<0) return res;
    	int width = matrix.front().size() - 1;
    	if(width<0) return res;

    	CPoint UpperLeft(0,0);
    	CPoint BottomLeft(0, height);
    	CPoint UpperRight(width,0);
    	CPoint BottomRight(width,height);

    	while(UpperLeft.x<=UpperRight.x && UpperLeft.y<=BottomLeft.y)
    	{
    		CPoint pivot;

    		if(UpperRight==UpperLeft)
    		{
    			for(pivot = UpperRight; pivot.y<=BottomRight.y; ++pivot.y) 
	    		{
	    			res.push_back(matrix[pivot.y][pivot.x]);
	    		}
	    		break;
    		}
    		else if(UpperLeft==BottomLeft)
    		{
    			for(pivot = UpperLeft; pivot.x<=UpperRight.x; ++pivot.x) 
	    		{
	    			res.push_back(matrix[pivot.y][pivot.x]);
	    		}
	    		break;
    		}
    		else
    		{
    			for(pivot = UpperLeft; pivot.x<UpperRight.x; ++pivot.x) 
	    		{
	    			res.push_back(matrix[pivot.y][pivot.x]);
	    		}
	    		for(pivot = UpperRight; pivot.y<BottomRight.y; ++pivot.y) 
	    		{
	    			res.push_back(matrix[pivot.y][pivot.x]);
	    		}
	    		for(pivot = BottomRight; pivot.x>BottomLeft.x; --pivot.x) 
	    		{
	    			res.push_back(matrix[pivot.y][pivot.x]);
	    		}
	    		for(pivot = BottomLeft; pivot.y>UpperLeft.y; --pivot.y) 
	    		{
	    			res.push_back(matrix[pivot.y][pivot.x]);
	    		}
	    		UpperLeft.x++;UpperLeft.y++;
	    		UpperRight.x--;UpperRight.y++;
	    		BottomLeft.x++;BottomLeft.y--;
	    		BottomRight.x--;BottomRight.y--;
    		}
    		
    	}
    	return res;
    }
};