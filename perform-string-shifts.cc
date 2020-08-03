#include <string>
#include <vector>

class Solution
{
public:
    std::string stringShift(const std::string &s, const std::vector<std::vector<int>> &shift)
    {
        int pos = 0;
        for (int i = 0; i < shift.size(); i++)
        {
            if (shift[i][0]) // right shift
            {
                pos -= shift[i][1];
                pos %= static_cast<int>(s.size());
                if (pos < 0)
                {
                    pos = s.size() + pos;
                }
            }
            else // left shift
            {
                pos += shift[i][1];
                pos %= s.size();
            }
        }
        std::string res;
        for (int i = 0; i < s.size(); i++)
        {
            res.push_back(s[pos++]);
            pos %= s.size();
        }
        return res;
    }
};