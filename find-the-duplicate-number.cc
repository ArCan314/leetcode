#include <vector>
#include <numeric>

class Solution
{
public:
    int findDuplicate(const std::vector<int> &nums)
    {
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int temp = (1 + nums.size() - 1) * (nums.size() - 1) / 2;
        return sum - temp;
    }
};