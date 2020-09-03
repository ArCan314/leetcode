#include <string>

class Solution
{
public:
    bool repeatedSubstringPattern(std::string s)
    {
        int len = 0;
        
        while (++len <= s.size() / 2)
        {
            if (s.size() % len) // s.size() is not multiple of len
                continue;
            
            bool res = true;
            int k = len;
            while (k < s.size())
            {
                for (int i = 0; i < len; i++)
                    if (s[i] != s[k++])
                    {
                        res = false;
                        break;
                    }
            }

            if (res)
                return true;
        }

        return false;
    }

};