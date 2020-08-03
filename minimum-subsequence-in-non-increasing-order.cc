#include <algorithm>
#include <vector>
#include <numeric>

class Solution
{
public:
    std::vector<int> minSubsequence(std::vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        std::vector<int> res;
        int sum = 0;
        int res_sum = 0;
        sum = std::accumulate(nums.begin(), nums.end(), 0);

        for (int i = nums.size() - 1; i >= 0; i--)
        {
            res_sum += nums[i];
            sum -= nums[i];
            res.push_back(nums[i]);
            if (res_sum > sum)
                break;
        }
        return res;
    }
};