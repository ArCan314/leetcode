#include <string>

class Solution
{
public:
    int numJewelsInStones(std::string J, std::string S)
    {
        bool has[256]{};
        for (const auto c : J)
            has[c] = true;
        
        int res = 0;
        for (const auto c : S)
            res += has[c];
        return res;
    }
};