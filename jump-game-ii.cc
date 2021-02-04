#include <vector>
#include <algorithm>

class Solution
{
public:
    int jump(std::vector<int> &nums)
    {
        return jumpGreedy(nums);
    }

    int jumpGreedy(std::vector<int> &nums)
    {
        if (nums.size() <= 1)
            return 0;

        int farthest = nums[0];
        int next_farthest = nums[0];
        int res = 1;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            next_farthest = std::max(next_farthest, nums[i] + i);
            if (i == farthest)
            {
                res++;
                farthest = next_farthest;
            }
        }
        return res;
    }

    int jumpDP(std::vector<int> &nums)
    {
        std::vector<int> dp(nums.size(), 1000000);
        std::vector<int> dp_temp(nums.size(), 1000000);
        dp[0] = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (i != 0 && nums[i] + i <= nums[dp_temp[i]] + dp_temp[i])
            {
                continue;
            }

            for (int j = i + 1; j <= nums[i] + i && j < nums.size(); j++)
            {
                if (dp[j] < dp[i] + 1)
                {
                    dp[j] = dp[i] + 1;
                    dp_temp[j] = i;
                }
            }
        }
        return dp[nums.size() - 1];
    }
};