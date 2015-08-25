#include <stack>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) 
	{
		stack<int> data;
		for(string &s : tokens)
		{
			if(isdigit(s.back()))
			{
				data.push(stoi(s));
			}
			else
			{
				int val2 = data.top();
				data.pop();
				int val1 = data.top();
				data.pop();
				switch(s.front())
				{
					case '+': data.push(val1+val2); break;
					case '-': data.push(val1-val2); break;
					case '*': data.push(val1*val2); break;
					case '/': data.push(val1/val2); break;
				}
			}
		}
		return data.top();
    }
};