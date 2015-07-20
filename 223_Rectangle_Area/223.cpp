class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) 
    {
        
    	int x_overlap = getOverlap(A, C, E, G);
    	int y_overlap = getOverlap(B, D, F, H);
		return getArea(A, B, C, D) + getArea(E, F, G, H) - x_overlap * y_overlap;

    }

    int getOverlap(int A1, int A2, int B1, int B2)
    {
    	int B1_pos = getPosition(B1,A1,A2);
    	int B2_pos = getPosition(B2,A1,A2);
    	
    	if (0==B1_pos && 0 == B2_pos) return B2-B1;
    	if (1 == B1_pos*B2_pos) return 0;
    	if (0 == B1_pos && 1==B2_pos) return A2-B1;
    	if (-1== B1_pos && 0==B2_pos) return B2-A1;
    	if (-1== B1_pos && 1==B2_pos) return A2-A1;

    	return 2;
    }

    int getPosition(int val, int low, int high)
    {
    	if(val<low) return -1;
    	if(val>high) return 1;
    	return 0;
    }

    int getArea(int left_bottom_x, int left_bottom_y, int right_top_x, int right_top_y)
    {
    	return (right_top_x - left_bottom_x)*(right_top_y - left_bottom_y);
    }
};