#include <string>
#include <array>

class Solution
{
public:
    int firstUniqChar(const std::string &s)
    {
        std::array<int, 26> count{};
        count.fill(-1);

        for (int i = 0; i < s.size(); i++)
        {
            int temp = count[s[i] - 'a'];
            if (temp == -1)
            {
                count[s[i] - 'a'] = i;
            }
            else if (temp >= 0)
            {
                count[s[i] - 'a'] = -2;
            }
        }

        int res = s.size();
        for (int i = 0; i < count.size(); i++)
        {
            if (count[i] >= 0)
            {
                res = std::min(res, count[i]);
            }
        }

        return (res == s.size()) ? -1 : res;
    }
};