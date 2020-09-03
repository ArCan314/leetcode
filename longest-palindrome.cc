#include <string>
#include <unordered_map>
#include <algorithm>

class Solution
{
public:
    int longestPalindrome(std::string &s)
    {
        int res = 0;
        std::unordered_map<char, int> collect;
        std::for_each(s.begin(), s.end(), [&collect](char c) { collect[c]++; });
        for (const auto &[c, freq] : collect)
        {
            if (res % 2)
                res += (freq % 2) ? freq - 1 : freq;
            else 
                res += freq;
        }
        return res;
    }
};