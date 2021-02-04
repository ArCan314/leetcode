#include <vector>
#include <algorithm>
#include <numeric>
#include <limits>

class Solution
{
public:
    double findMaxAverage(std::vector<int> &nums, int k)
    {
        int left = 0, right = k;
        int sum = std::accumulate(nums.begin(), nums.begin() + k, 0);
        double res = static_cast<double>(sum) / static_cast<double>(k);
        while (right < nums.size())
        {
            res = std::max(res, static_cast<double>(sum) / static_cast<double>(k));
            sum += nums[right++];
            sum -= nums[left++];
        }
        return std::max(res, static_cast<double>(sum) / static_cast<double>(k));
    }
};