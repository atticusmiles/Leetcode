#include <stdlib.h>
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t before,after;
        before=0x80000000;
        after=0x1;
        uint32_t result;
        while (before>after)
        {
        	result+=before*(0!=(n&after));
        	result+=after*(0!=(n&before));
        	before/=2;
        	after*=2;
        }
        return result;
    }
};