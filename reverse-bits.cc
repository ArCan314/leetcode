#include <cstdint>

class Solution
{
public:
    uint32_t reverseBits(uint32_t n)
    {
        return reverseBitsPerbit(n);
    }

    uint32_t reverseBitsPerbit(uint32_t n)
    {
        uint32_t lmask = 0x80000000u, rmask = 1u, res = 0;

        for (int i = 0; i < 32; i++)
        {
            if (n & rmask)
                res |= lmask;
            rmask <<= 1;
            lmask >>= 1;
        }
        return res;
    }
};