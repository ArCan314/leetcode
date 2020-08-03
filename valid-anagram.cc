#include <string>
#include <array>

class Solution
{
public:
    bool isAnagram(std::string &s, std::string &t)
    {
        std::array<char, 26> count{};
        for (const auto c : s)
            count[c - 'a']++;
        for (const auto c : t)
            count[c - 'a']--;

        for (const auto i : count)
            if (i)
                return false;
        return true;
    }
};