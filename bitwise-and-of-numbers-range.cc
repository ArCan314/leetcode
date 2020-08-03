class Solution
{
public:
    int rangeBitwiseAnd(int m, int n)
    {
        int res = 0;
        for (int i = 0x40000000; i; i >>= 1)
        {
            if (n - m < i && (n & i) && (m & i))
            {
                res |= i;
            }
        }
        return res;
    }
};