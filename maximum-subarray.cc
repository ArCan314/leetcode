#include <vector>

class Solution
{
public:
    int maxSubArray(const std::vector<int> &nums)
    {
        if (nums.empty())
            return 0;

        int max = nums.front();
        std::vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            if (dp[i - 1] < 0 && nums[i] > dp[i - 1])
            {
                dp[i] = nums[i];
            }
            else
            {
                dp[i] = dp[i - 1] + nums[i];
            }
            max = std::max(max, dp[i]);
        }

        return max;
    }
};