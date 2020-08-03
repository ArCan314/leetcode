#include <cstdio>

class Solution
{
public:
    int getSum(int a, int b)
    {
        int c = 0;
        int s = 0;
        int mask = 1;
        int res = 0;
        printf("0x%08X, 0x%08X\n", a, b);
        for (int i = 1; i < 32; i++)
        {
            s = (a & mask) ^ (b & mask) ^ (c & mask);
            c = (((a & mask) ^ (b & mask)) & c) | ((a & mask) & (b & mask));
            c <<= 1;
            mask <<= 1;
            res |= s;
            printf("%2d, 0x%08X, 0x%08X, 0x%08X\n", i, s, c, res);
        }
        s = (a & mask) ^ (b & mask) ^ (c & mask);
        c = (((a & mask) ^ (b & mask)) & c) | ((a & mask) & (b & mask));
        res |= s;
        printf("32, 0x%08X, 0x%08X, 0x%08X\n", s, c, res);
        return res;
    }
};