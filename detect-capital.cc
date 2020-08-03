#include <string>
#include <cctype>

class Solution
{
public:
    bool detectCapitalUse(const std::string &word)
    {
        bool is_first_capital = std::isupper(word.front());
        int capital_count = is_first_capital;
        for (int i = 1; i < word.size(); i++)
            capital_count += std::isupper(word[i]) ? 1 : 0;
        if (capital_count == word.size())
            return true;
        else if (capital_count == 1 && is_first_capital)
            return true;
        else if (capital_count == 0)
            return true;
        return false;
    }
};