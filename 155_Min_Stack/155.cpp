#include <vector>
using namespace std;

class MinStack {
public:
    void push(int x) 
    {
        pair<int,int> unit={x,x};

        if(data.size()==0 || x<data.back().second)
        {
            data.push_back(unit);
        }
        else
        {
            unit.second = data.back().second;
            data.push_back(unit);
        }

    }

    void pop() 
    {
    	data.pop_back();
    }

    int top() 
    {
    	return data.back().first;
    }

    int getMin() 
    {
        return data.back().second;
    }
private:
    vector<pair<int,int>> data;

};