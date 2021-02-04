#include <deque>
#include <vector>
#include <iostream>

class Solution
{
public:
    int findCircleNum(std::vector<std::vector<int>> &isConnected)
    {
        int n = isConnected.size();
        std::vector<int> visit(n, 0);
        std::deque<int> expand;
        int count = 0;
        int res = 0;
        expand.push_back(0);
        visit[0] = 1;
        
        while (count < n)
        {
            res++;
            // std::cout << "round" << res << std::endl;
            while (!expand.empty())
            {
                int next = expand.front();
                expand.pop_front();
                // std::cout << "\tvisit " << next << std::endl; 

                count++;
                for (int i = 0; i < n; i++)
                {
                    if (!visit[i] && isConnected[next][i])
                    {
                        visit[i] = 1;
                        expand.push_back(i);
                    }
                }
            }
            // std::cout << "round end" << std::endl;
            if (count < n)
            {
                for (int i = 0; i < n; i++)
                    if (!visit[i])
                    {
                        // std::cout << "new round add: v: " << i << std::endl;
                        expand.push_back(i);
                        visit[i] = 1;
                        break;
                    }
            }
        }
        return res;
    }
};