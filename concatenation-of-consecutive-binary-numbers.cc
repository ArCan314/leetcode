#include <vector>

class Solution
{
public:
    int concatenatedBinary(int n)
    {
        long long init = 0;
        int k = 1;
        int bound = 1;
        int count = 0;
        while (count < n)
        {
            if (count == bound)
            {
                k++;
                bound = (bound << 1) | 1;
            }

            count++;
            init = (init << k) + count;
            init %= 1000000007;
        }
        return static_cast<int>(init);
    }
};