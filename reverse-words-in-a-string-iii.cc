#include <string>
#include <algorithm>

class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        int start = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == ' ')
            {
                std::reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }
        std::reverse(s.begin() + start, s.end());
        return s;
    }
};