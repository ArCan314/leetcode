#include <vector>
#include <queue>
class Solution
{
public:
    int constrainedSubsetSum(std::vector<int> &nums, int k)
    {
        if (!nums.size())
            return 0;

        std::vector<int> dp(nums.size(), -100000);
        std::priority_queue<std::pair<int, int>> pq;

        dp[0] = nums[0];
        int res = nums[0];
        pq.push({dp[0], 0});
        for (int i = 1; i < nums.size(); i++)
        {
            dp[i] = nums[i];
            while (pq.size())
            {
                if (pq.top().second < i - k)
                    pq.pop();
                else
                {
                    dp[i] = std::max(dp[i], pq.top().first + dp[i]);
                    break;
                }
            }
            pq.push({dp[i], i});
            res = std::max(res, dp[i]);
        }
        return res;
    }
};