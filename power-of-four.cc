#include <unordered_set>

static const std::unordered_set<int> lut =
    {
        1,
        4,
        4 << 2,
        4 << 4,
        4 << 6,
        4 << 8,
        4 << 10,
        4 << 12,
        4 << 14,
        4 << 16,
        4 << 18,
        4 << 20,
        4 << 22,
        4 << 24,
        4 << 26,
        4 << 28,
};

class Solution
{
public:
    bool isPowerOfFourLUT(int num) // O(1)
    {
        return lut.count(num);
    }

    bool isPowerOfFour(int num)
    {
        return num > 0 && !(num & (num - 1)) && (num & 0x55555555);
    }
};