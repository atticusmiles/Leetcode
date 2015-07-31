#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
    	int height = matrix.size();
    	int width = matrix.front().size();
    	int head = 0;
    	int tail = height - 1;

    	int line_res;

    	while(head<=tail)
    	{
    		int tmp = (head+tail)/2;
    		if(matrix[tmp][0]<target)
    		{
    			head = tmp+1;
    		}
    		else if(matrix[tmp][0]>target)
    		{
    			tail = tmp-1;
    		}
    		else
    		{
    			return true;
    		}
    	}    
    	line_res = tail;
    	if(line_res<0) return false;

        head = 0; tail = width -1;

        while(head<=tail)
        {
            int tmp = (head+tail)/2;
            if(matrix[line_res][tmp]<target)
            {
                head = tmp+1;
            }
            else if(matrix[line_res][tmp]>target)
            {
                tail = tmp-1;
            }
            else
            {
                return true;
            }
        }
        return false;
    	
    }
};