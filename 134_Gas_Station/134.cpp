#include <vector>
using namespace std;


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
		vector<int> gas_gain = gas;
		for(int i=0; i<gas_gain.size(); ++i)
		{
			gas_gain[i] -= cost[i];
		}

		int head = 0;
		int tail = 0;

		int gas_in_car =0;
		while(1)
		{
			gas_in_car+=gas_gain[tail];
			tail= (tail+1) % gas.size();
			while(gas_in_car<0)
			{
				head = (head+gas.size()-1)%gas.size();
				gas_in_car+=gas_gain[head];
				if(head ==tail && gas_in_car<0) return -1;
			}
			if(tail==head) return head;
			
		}
    }
};