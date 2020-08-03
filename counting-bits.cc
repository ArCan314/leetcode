#include <vector>

class Solution
{
public:
    static int countOnes(int num)
    {
        int count = 0;
        while (num)
        {
            count += num % 2;
            num /= 2; 
        }
        return count;
    }

    std::vector<int> countBitsUnOpt(int num) // O(sizeof(n) * n)
    {
        std::vector<int> res(num + 1, 0);
        for (int i = 0; i < num + 1; i++)
            res[i] = countOnes(i);
        return res;
    }

    std::vector<int> countBits(int num) // O(n)
    {
        std::vector<int> res(num + 1, 0);
        if (num >= 1)
            res[1] = 1;
        int lb = 2, now = 2;
        while (now < num + 1)
        {
            for (int i = 0; i < lb && now < num + 1; i++)
                res[now++] = res[i] + 1;
            lb *= 2;
        }
        return res;
    }
};