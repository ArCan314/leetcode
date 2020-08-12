#include <string>

class Solution
{
public:
    std::string replaceSpace(std::string s)
    {
        std::string res;
        for (const auto c : s)
            if (c == ' ')
                res.append("%20");
            else
                res.push_back(c);
        return res;
    }
};