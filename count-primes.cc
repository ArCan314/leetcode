#include <vector>

class Solution
{
public:
    int countPrimes(int n)
    {
        std::vector<char> table(n, 0);
        int res = 0;
        for (int i = 2; i < n; i++)
        {
            if (!table[i])
            {
                res++;
                for (int j = 2 * i; j < n; j+= i)
                {
                    table[j] = 1;
                }
            }
        }
        return res;
    } 
};