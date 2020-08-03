#include <array>
#include <algorithm>

class Solution
{
public:
    int getDigitSum(int n) const noexcept
    {
        int res = 0;
        while (n)
        {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    int countLargestGroup(int n)
    {
        constexpr int kArrSize = 50; 
        std::array<int, kArrSize> temp{};
        int count = 0;
        int res = 0;

        for (int i = 1; i <= n; i++)
        {
            int digit_sum = getDigitSum(i);
            temp[digit_sum]++;
            count = std::max(temp[digit_sum], count);
        }
        
        for (int i = 0; i < kArrSize; i++)
            res += (temp[i] == count);

        return res;
    }
};