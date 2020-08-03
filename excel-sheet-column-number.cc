#include <string>

class Solution
{
public:
    int titleToNumber(std::string &s)
    {
        int res = 0;

        for (int i = s.size() - 1; i >= 0; i--)
        {
            res *= 26;
            res += s[i] - 'A' + 1;
        }
        return res;
    }
};