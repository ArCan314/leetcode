#include <string>
#include <cctype>

class Solution
{
public:
    void preprocess(std::string &s)
    {
        std::string temp;
        for (const auto c : s)
            if (std::isalnum(c))
                temp.push_back(std::tolower(c));
        s.swap(temp);
    }

    bool isPalindrome(std::string &s)
    {
        preprocess(s);
        int l = 0, r = s.size() - 1;
        while (l < r)
            if (s[l++] != s[r--])
                return false;
        return true;
    }
};