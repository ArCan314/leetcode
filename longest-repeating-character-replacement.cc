#include <string>
#include <numeric>
#include <algorithm>
#include <array>

class Solution
{
public:
    int characterReplacement(std::string &s, int k)
    {
        int l = 0, r = 0, res = 0;
        std::array<int, 26> freq{};

        while (r < s.size())
        {
            auto max_elem = std::max_element(freq.begin(), freq.end());

            if (r - l - *max_elem <= k)
            {
                res = std::max(r - l, res);
                freq[s[r++] - 'A']++;
            }
            else
            {
                freq[s[l++] - 'A']--;
            }
        }

        auto max_elem = std::max_element(freq.begin(), freq.end());

        if (r - l - *max_elem <= k)
            res = std::max(r - l, res);

        return res;
    }
};