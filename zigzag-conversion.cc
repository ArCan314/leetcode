#include <string>
#include <vector>
#include <numeric>
#include <algorithm>

class Solution
{
public:
    std::string convert(const std::string &s, int numRows)
    {
        if (numRows < 2)
            return s;
        
        std::string res;
        for (int i = 0; i < numRows; i++)
        {
            int j = i;
            int k = 0;
            int bias[2] = {2 * (numRows - 1 - i), 2 * i};
            if (bias[0] <= 0 || bias[1] <= 0)
            {
                bias[0] = std::max(bias[0], bias[1]);
                bias[1] = std::max(bias[0], bias[1]);
            }
            while (j < s.size())
            {
                res.push_back(s[j]);
                j += bias[k % 2];
                k = !k;
            }
        }
        return res;
    }
};
