#include <stack>
#include <vector>


class Solution {
public:
    std::vector<int> dailyTemperaturesBruteForce(const std::vector<int>& t) 
    {
        std::vector<int> res(t.size(), 0);

        for (int i = 0; i < t.size(); i++)
        {
            for (int j = i + 1; j < t.size(); j++)
            {
                if (t[j] > t[i])
                {
                    res[i] = j - i;
                    break;
                }
            }
        }

        return res;
    }

    std::vector<int> dailyTemperatures(const std::vector<int>& t) 
    {
        std::vector<int> res(t.size(), 0);
        std::stack<int> ind;

        for (int i = 0; i < t.size(); i++)
        {
            while (!ind.empty() && t[ind.top()] < t[i])
            {
                res[ind.top()] = i - ind.top();
                ind.pop();
            }
            ind.push(i);
        }

        return res;
    }
};