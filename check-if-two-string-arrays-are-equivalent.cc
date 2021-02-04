#include <string>
#include <vector>

class Solution
{
public:
    bool arrayStringsAreEqual(std::vector<std::string> &word1, std::vector<std::string> &word2)
    {
        std::string s1, s2;
        for (const auto &s : word1)
            s1.append(s);

        for (const auto &s: word2)
            s2.append(s);
        return s1 == s2;
    }

};