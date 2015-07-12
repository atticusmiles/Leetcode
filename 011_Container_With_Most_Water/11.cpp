#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        int begin = 0;
        int end = height.size() - 1;

        int max_area = 0;

        int height_before = 0;

        while(end>begin)
        {
        	
        	while (height[begin]<=height_before) ++begin;
        	while (height[end]<=height_before) --end;
        	height_before = min(height[begin],height[end]);

        	int area = (end-begin)*height_before;

        	max_area=(area>max_area) ? area : max_area; 
        }

        return max_area;
    }
};