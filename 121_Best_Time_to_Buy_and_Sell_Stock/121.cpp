#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
    	if(prices.size()==0) return 0;
        int min_till_now=prices.front();
        int max_after_min=min_till_now;
        int max_profit = 0;
        for(auto &i : prices)
        {
        	if(i<min_till_now)
        	{
        		min_till_now = i;
        		max_after_min = i;
        	}
        	else if(i>max_after_min)
        	{
        		max_after_min = i;
        		max_profit = (max_profit>(max_after_min-min_till_now))? max_profit : max_after_min-min_till_now;
        	}
        }
        return max_profit;
    }
};