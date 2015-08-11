#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
    	if(prices.size()==0) return 0;
        int min_after_last_sell=prices.front();
        int max_after_min=min_after_last_sell;
        int profit = 0;
        for(auto &i : prices)
        {
        	if(i<max_after_min)
        	{
        		profit+=max_after_min - min_after_last_sell;
        		min_after_last_sell = i;
        		max_after_min = i;
        	}
        	else
        	{
        		max_after_min = i;
        	}
        }
        if (max_after_min>min_after_last_sell) 
        {
        	profit+=max_after_min - min_after_last_sell;
        }
        return profit;
    }
};