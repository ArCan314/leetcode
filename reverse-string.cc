#include <vector>
#include <algorithm>

class Solution
{
public:
    void reverseStringSTD(std::vector<char> &s)
    {
        std::reverse(s.begin(), s.end());
    }
    void reverseString(std::vector<char> &s)
    {
        int l = 0, r = s.size() - 1;
        while (l < r)
            std::swap(s[l++], s[r--]);
    }
};