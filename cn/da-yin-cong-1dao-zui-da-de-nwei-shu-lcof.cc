#include <vector>

class Solution
{
public:
    std::vector<int> printNumbers(int n)
    {
        int count = 1;
        int bound = 1;
        int level = 0;
        std::vector<int> res;

        while (level < n)
        {
            bound *= 10;
            while (count < bound)
            {
                res.push_back(count++);
            }
            level++;
        }

        return res;
    }
};