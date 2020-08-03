#include <string>
#include <deque>
#include <iostream>

class Solution
{
public:
    int numSteps(const std::string &s)
    {
        int res = 0;
        std::deque<char> dq(s.begin(), s.end());
        while (dq.size() != 1 || (dq.size() == 1 && dq[0] == '0'))
        {
            std::cout << dq.size() << std::endl;
            res++;
            if (dq[dq.size() - 1] == '0')
            {
                dq.pop_back();
            }
            else
            {
                int i;
                for (i = dq.size() - 1; i >= 0; i--)
                {
                    if (dq[i] == '0')
                    {
                        dq[i] = '1';
                        break;
                    }
                    else
                    {
                        dq[i] = '0';
                    }
                }

                if (i < 0)
                    dq.push_front('1');
            }
        }
        return res;
    }
};