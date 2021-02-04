#include <string>
#include <vector>
#include <array>
#include <algorithm>

class Solution
{
public:
    bool closeStrings(std::string &word1, std::string &word2)
    {
        if (word1.size() != word2.size())
            return false;

        std::array<int, 26> freq1{}, freq2{};
        std::array<int, 26> exist1{}, exist2{};

        for (const auto c : word1)
        {
            freq1[c - 'a']++;
            exist1[c - 'a'] = 1;
        }

        for (const auto c : word2)
        {
            freq2[c - 'a']++;
            exist2[c - 'a'] = 1;
        }

        std::sort(freq1.begin(), freq1.end());
        std::sort(freq2.begin(), freq2.end());
        
        return (exist1 == exist2) ? (freq1 == freq2) : false;
    }
};