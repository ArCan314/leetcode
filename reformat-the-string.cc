#include <vector>
#include <string>
#include <cctype>

class Solution
{
public:
    std::string reformat(std::string s)
    {
        if (!s.size())
            return "";
        int count[2]{}; // digit, alpha
        for (const auto c : s)
            count[std::isalpha(c) ? 1 : 0]++;

        std::string res;
        if (std::abs(count[0] - count[1]) <= 1)
        {
            res.resize(s.size());
            int alpha{}, digit{};
            if (count[0] < count[1])
            {
                for (int i = 0; i < s.size(); i++)
                {
                    if (std::isalpha(s[i]))
                    {
                        res[2 * alpha++] = s[i];
                    }
                    else
                    {
                        res[2 * (digit++) + 1] = s[i];
                    }
                }
            }
            else
            {
                for (int i = 0; i < s.size(); i++)
                {
                    if (std::isalpha(s[i]))
                    {
                        res[2 * (alpha++) + 1] = s[i];
                    }
                    else
                    {
                        res[2 * digit++] = s[i];
                    }
                }
            }
        }   
        return res;
    }
};