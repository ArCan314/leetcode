#include <vector>
#include <algorithm>

class Solution
{
public:
    std::vector<int> exchange(std::vector<int> &nums)
    {
        exchangePartition(nums);
        return nums;
    }

    void exchangeLinear(std::vector<int> &nums)
    {
        int i = 0, j = 0;
        while (j < nums.size())
        {
            if (nums[j] % 2)
                std::swap(nums[i++], nums[j]);
            j++;
        }
    }

    void exchangePartition(std::vector<int> &nums)
    {
        std::partition(nums.begin(), nums.end(), [](auto a) { return a % 2; });
    }
};