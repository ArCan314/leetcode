#include <string>
#include <list>
#include <algorithm>

class Solution
{
public:
    bool checkValidString(std::string &s)
    {
        std::list<char> stack;
        bool is_failed = false;
        for (int i = 0; !is_failed && i < s.size(); i++)
        {
            switch (s[i])
            {
            case '(':
                stack.push_back('(');
                break;
            case '*':
                stack.push_back('*');
                break;
            case ')':
            {
                auto iter = std::find(stack.rbegin(), stack.rend(), '(');
                if (iter != stack.rend())
                {
                    stack.erase(--(iter.base()));
                }
                else
                {
                    iter = std::find(stack.rbegin(), stack.rend(), '*');
                    if (iter != stack.rend())
                    {
                        stack.erase(--(iter.base()));
                    }
                    else
                    {
                        is_failed = true;
                    }
                }
                break;
            }
            }
        }
        
        // std::for_each(stack.begin(), stack.end(), [](char c){std::cout << c << ", ";});
        // std::cout << std::endl;
        while (!is_failed && stack.size())
        {
            // std::for_each(stack.begin(), stack.end(), [](char c){std::cout << c << ", ";});
            // std::cout << std::endl;
            if (stack.back() == '(')
            {
                is_failed = true;
            }
            else
            {
                auto iter = std::find(stack.rbegin(), stack.rend(), '(');
                if (iter != stack.rend())
                {
                    stack.erase(--(iter.base()));
                    stack.pop_back();
                }
                else
                {
                    break;
                }
            }
        }

        return !is_failed;
    }
};