#include <stack>

class CQueue
{
public:
    CQueue()
    {
    }

    void appendTail(int value)
    {
        in.push(value);
    }

    int deleteHead()
    {
        if (!in.size() && !out.size())
            return -1;

        if (!out.size())
        {
            while (in.size())
            {
                out.push(in.top());
                in.pop();
            }
        }

        int res = out.top();
        out.pop();
        return res;
    }

private:
    std::stack<int> in, out;
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */