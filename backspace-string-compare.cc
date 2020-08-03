#include <string>

class Solution
{
public:
    void backspaceGen(const std::string &str, std::string &dest) const
    {
        dest.clear();
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '#' && dest.size())
                dest.pop_back();
            else if (str[i] != '#')
                dest.push_back(str[i]);
        }
    }

    bool backspaceCompare(const std::string &S, const std::string &T) const
    {
        std::string a, b;
        backspaceGen(S, a);
        backspaceGen(T, b);
        return a == b;
    }
};