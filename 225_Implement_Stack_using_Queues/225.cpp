#include <queue>
using namespace std;

class Stack {
public:
    // Push element x onto stack.
    void push(int x) 
    {
        tmp.push(x);
        while(!data.empty())
        {
            tmp.push(data.front());
            data.pop();
        }
        data.swap(tmp);
    }

    // Removes the element on top of the stack.
    void pop() 
    {
        data.pop();
    }

    // Get the top element.
    int top() 
    {
        return data.front();
    }

    // Return whether the stack is empty.
    bool empty() 
    {
        return data.empty();
    }
    queue <int> data;
    queue <int> tmp;
};  