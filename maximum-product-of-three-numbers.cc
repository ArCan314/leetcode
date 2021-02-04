#include <vector>
#include <algorithm>

class Solution
{
public:
    int maximumProduct(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int size = nums.size();
        int a = nums[0] * nums[1] * nums[2];
        int b = nums[size - 1] * nums[size - 2] * nums[size - 3];
        int c = nums[size - 1] * nums[0] * nums[1];
        int d = nums[size - 2] * nums[size - 1] * nums[0];
        return std::max(std::max(a, b), std::max(c, d));
    }
};