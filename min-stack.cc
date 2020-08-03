#include <vector>
#include <utility>

class MinStack
{
private:
    std::vector<std::pair<int, int>> _stack; // {cur, min}

public:
    /** initialize your data structure here. */
    MinStack()
    {
    }

    void push(int x)
    {
        if (_stack.size())
        {
            _stack.push_back({x, std::min(x, _stack.back().second)});
        }
        else
            _stack.push_back({x, x});
    }

    void pop()
    {
        if (_stack.size())
            _stack.pop_back();
    }

    int top()
    {
        return _stack.back().first;
    }

    int getMin()
    {
        return _stack.back().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */