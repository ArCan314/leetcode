#include <string>

class Solution
{
public:
    int lengthOfLongestSubstring(std::string &s) const
    {
        int l = 0, r = 0, len = 0;
        int has[255]{};

        while (r < s.size())
        {
            while ( r < s.size() && !has[s[r]])
                has[s[r++]]++;

            if (len < r - l)
                len = r - l;

            has[s[l++]]--;
        }

        return len;
    }
};