#include <vector>
#include <string>
#include <set>
#include <deque>
#include <algorithm>
#include <array>

class Solution
{
public:
    std::vector<int> findAnagrams(const std::string &s, const std::string &p)
    {
        if (s.size() < p.size())
            return {};

        std::array<int, 26> count{}, window_count{};
        std::vector<int> res;
        for (const auto pattern_c : p)
            count[pattern_c - 'a']++;


        int l, r;
        l = r = 0;
        for (r = 0; r < p.size(); r++)
            window_count[s[r] - 'a']++;
        
        while (r < s.size())
        {
            if (count == window_count)
                    res.push_back(l);

            window_count[s[l++] - 'a']--;
            window_count[s[r++] - 'a']++;
        }

        if (count == window_count)
            res.push_back(l);

        return res;
    }
};