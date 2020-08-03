#include <string>
#include <vector>

class Solution
{
public:
    int maxScore(std::string &s)
    {
        std::vector<int> zeros(s.size() + 1, 0);
        std::vector<int> ones(s.size() + 1, 0);

        for (int i = 1; i <= s.size(); i++)
        {
            if (s[i] == '0')
                zeros[i]++;
            zeros[i] += zeros[i - 1];
        }

        for (int i = s.size(); i >= 0; i--)
        {
            if (s[i] == '1')
                ones[i]++;
            ones[i] += ones[i + 1];
        }

        int res = 0;
        for (int i = 1; i < s.size(); i++)
        {
            res = std::max(zeros[i] + ones[i], res);
        }
        return res;
    }
};