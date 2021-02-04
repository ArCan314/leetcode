#include <cstdint>

class Solution
{
public:
    int hammingWeight(std::uint32_t n)
    {
        int table[] = {0, 1, 1, 2, 1, 2, 2, 3, 1, 2, 2, 3, 2, 3, 3, 4};
        int res = 0;
        while (n)
        {
            res += table[n & 0xf];
            n >>= 4;
        }
        return res;
    }
};