#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
    	auto iter1 = nums1.begin();
    	auto iter2 = nums2.begin();

    	for (iter2 = nums2.begin(); iter2<(nums2.begin()+n); ++iter2)
    	{
    		while(*iter1<*iter2 && (iter1-nums1.begin())<(m+iter2-nums2.begin()))
    		{
    			++iter1;
    		}
    		
            nums1.erase(nums1.end()-1);
			nums1.insert(iter1, *iter2);
    		
    	}    
    }
};