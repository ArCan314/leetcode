#include <vector>
#include <string>

class Solution {
public:

    constexpr static char par(const char c) noexcept
    {
        if (c == ')')
            return '(';
        else if (c == '}')
            return '{';
        else
            return '[';
    }

    bool isValid(std::string &s) 
    {
        std::vector<char> stack;
        for (int i = 0; i < s.size(); i++)
        {
            switch(s[i])
            {
            case '(':
            case '{':
            case '[':
                stack.push_back(s[i]);
                break;
            default:
                if (stack.size() && stack.back() == par(s[i]))
                    stack.pop_back();
                else 
                    return false;
                break;
            }
        }

        return !stack.size();
    }
};